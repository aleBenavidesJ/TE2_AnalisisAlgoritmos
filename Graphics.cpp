#include <gtkmm.h>
#include <cairomm/cairomm.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

class GraphDrawingArea : public Gtk::DrawingArea {
public:
    GraphDrawingArea(const std::vector<double>& bubbleTimes,
                     const std::vector<double>& selectionTimes,
                     const std::vector<double>& mergeTimes,
                     const std::vector<double>& linkedListTimes,
                     const std::vector<double>& bstTimes,
                     const std::vector<int>& sizes,
                     const std::string& title)
        : bubbleTimes(bubbleTimes),
          selectionTimes(selectionTimes),
          mergeTimes(mergeTimes),
          linkedListTimes(linkedListTimes),
          bstTimes(bstTimes),
          sizes(sizes),
          title(title) {
        set_size_request(800, 600);
    }

protected:
    std::vector<double> bubbleTimes;
    std::vector<double> selectionTimes;
    std::vector<double> mergeTimes;
    std::vector<double> linkedListTimes;
    std::vector<double> bstTimes;
    std::vector<int> sizes;
    std::string title;

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override {
    cr->set_source_rgb(1, 1, 1);
    cr->paint();
    cr->set_source_rgb(0, 0, 0);
    cr->select_font_face("Arial", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
    cr->set_font_size(16);
    cr->move_to(50, 30);
    cr->show_text(title);

    double maxTime = 0;
    std::vector<std::vector<double>> times = {bubbleTimes, selectionTimes, mergeTimes, linkedListTimes, bstTimes};
    for (const auto& algorithmTimes : times) {
        double localMax = *std::max_element(algorithmTimes.begin(), algorithmTimes.end());
        if (localMax > maxTime) {
            maxTime = localMax;
        }
    }

    if (maxTime < 1) {
        maxTime = 1;
    }

    cr->set_line_width(2.0);
    cr->move_to(100, 50);
    cr->line_to(100, 500);
    cr->move_to(100, 500);
    cr->line_to(700, 500);
    cr->stroke();
    cr->move_to(100, 510);
    cr->show_text("1000");
    for (size_t i = 0; i < sizes.size(); ++i) {
        double x = 100 + (600 * (i + 1) / (sizes.size() + 1));
        cr->move_to(x, 510);
        cr->show_text(std::to_string(sizes[i]));
    }

    cr->move_to(60, 60);
    cr->show_text("Tiempo (s)");
    cr->move_to(350, 530);
    cr->show_text("Tamaño del arreglo (N)");

    int numLabels = 5;
    for (int i = 0; i <= numLabels; ++i) {
        double labelY = 500 - (500 * i / numLabels);
        cr->move_to(60, labelY);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << (maxTime * i / numLabels);
        cr->show_text(oss.str());
        cr->set_source_rgb(0.8, 0.8, 0.8);
        cr->move_to(100, labelY);
        cr->line_to(700, labelY);
        cr->stroke();
    }

    for (size_t i = 0; i < times.size(); ++i) {
        set_color(cr, i);
        cr->move_to(100, 500 - (times[i][0] * 450 / maxTime));
        for (size_t j = 0; j < sizes.size(); ++j) {
            double x = 100 + (600 * (j + 1) / (sizes.size() + 1));
            double y = 500 - (times[i][j] * 450 / maxTime);
            cr->line_to(x, y);
        }
        cr->stroke();
    }

    std::vector<std::string> labels = {"BubbleSort", "SelectionSort", "MergeSort", "LinkedList Search", "BST Insert"};
    for (size_t i = 0; i < times.size(); ++i) {
        double labelX = 100 + (600 * (i + 0.5) / times.size());
        double labelY = 540;
        set_color(cr, i);
        cr->move_to(labelX, labelY);
        cr->show_text(labels[i]);
    }
    return true;
}

    void set_color(const Cairo::RefPtr<Cairo::Context>& cr, int index) {
        switch (index) {
            case 0: cr->set_source_rgb(1, 0, 0); break;
            case 1: cr->set_source_rgb(0, 1, 0); break;
            case 2: cr->set_source_rgb(0, 0, 1); break;
            case 3: cr->set_source_rgb(1, 0.5, 0); break;
            case 4: cr->set_source_rgb(0.5, 0, 1); break;
        }
    }
};

class GraphicsWindow : public Gtk::Window {
public:
    GraphicsWindow(const std::vector<double>& bubbleWorst,
                   const std::vector<double>& bubbleBest,
                   const std::vector<double>& bubbleAvg,
                   const std::vector<double>& selectionWorst,
                   const std::vector<double>& selectionBest,
                   const std::vector<double>& selectionAvg,
                   const std::vector<double>& mergeWorst,
                   const std::vector<double>& mergeBest,
                   const std::vector<double>& mergeAvg,
                   const std::vector<double>& linkedListWorst,
                   const std::vector<double>& linkedListBest,
                   const std::vector<double>& linkedListAvg,
                   const std::vector<double>& bstWorst,
                   const std::vector<double>& bstBest,
                   const std::vector<double>& bstAvg,
                   const std::vector<int>& sizes) {

        set_title("Tiempos de ejecución");
        set_default_size(800, 600);
        set_resizable(false);
        Gtk::Notebook* notebook = Gtk::make_managed<Gtk::Notebook>();
        Gtk::Box* worstCaseTab = Gtk::make_managed<Gtk::Box>(Gtk::ORIENTATION_VERTICAL, 10);
        Gtk::Box* bestCaseTab = Gtk::make_managed<Gtk::Box>(Gtk::ORIENTATION_VERTICAL, 10);
        Gtk::Box* avgCaseTab = Gtk::make_managed<Gtk::Box>(Gtk::ORIENTATION_VERTICAL, 10);
        worstCaseTab->pack_start(*Gtk::make_managed<GraphDrawingArea>(bubbleWorst, selectionWorst, mergeWorst, linkedListWorst, bstWorst, sizes, "Worst Case"), Gtk::PACK_EXPAND_WIDGET);
        bestCaseTab->pack_start(*Gtk::make_managed<GraphDrawingArea>(bubbleBest, selectionBest, mergeBest, linkedListBest, bstBest, sizes, "Best Case"), Gtk::PACK_EXPAND_WIDGET);
        avgCaseTab->pack_start(*Gtk::make_managed<GraphDrawingArea>(bubbleAvg, selectionAvg, mergeAvg, linkedListAvg, bstAvg, sizes, "Average Case"), Gtk::PACK_EXPAND_WIDGET);
        notebook->append_page(*worstCaseTab, "Peor Caso");
        notebook->append_page(*bestCaseTab, "Mejor Caso");
        notebook->append_page(*avgCaseTab, "Caso Promedio");
        add(*notebook);
        show_all_children();
    }
};