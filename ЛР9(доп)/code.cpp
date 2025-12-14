#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

using std::vector;

/* ================= Fake UNet ================= */
class UNet {
public:
    double conv1_weight = 0.5;   // отслеживаемый вес

    double dice_loss(double p, double y) {
        return 1.0 - (2*p*y + 1e-6) / (p + y + 1e-6);
    }

    double accuracy(double loss) {
        return 1.0 - loss;
    }

    void train(int epochs) {
        std::cout << "\nEpoch | Loss ↓ | Accuracy ↑ | conv1_w\n";
        std::cout << "------------------------------------\n";

        vector<double> losses;
        vector<double> accs;

        for (int e = 0; e <= epochs; ++e) {
            // --- ИМИТАЦИЯ обучения ---
            double loss = std::exp(-e / 50.0);
            double acc  = accuracy(loss);

            conv1_weight += 0.002 * acc;

            losses.push_back(loss);
            accs.push_back(acc);

            if (e % 20 == 0) {
                std::cout << std::setw(4) << e << " | "
                          << std::fixed << std::setprecision(3)
                          << loss << " | "
                          << acc << " | "
                          << conv1_weight << "\n";
            }
        }

        draw_loss_graph(losses);
        draw_accuracy_graph(accs);
    }

    /* ===== ASCII график потерь ===== */
    void draw_loss_graph(const vector<double>& losses) {
        std::cout << "\nLOSS GRAPH (ASCII)\n";
        std::cout << "-----------------\n";

        for (size_t i = 0; i < losses.size(); i += 10) {
            int bars = static_cast<int>(losses[i] * 25);
            std::cout << std::setw(3) << i << " | ";
            for (int j = 0; j < bars; ++j)
                std::cout << "█";
            std::cout << " (" << std::fixed << std::setprecision(3)
                      << losses[i] << ")\n";
        }
    }

    /* ===== ASCII график точности ===== */
    void draw_accuracy_graph(const vector<double>& accs) {
        std::cout << "\nACCURACY GRAPH (ASCII)\n";
        std::cout << "---------------------\n";

        for (size_t i = 0; i < accs.size(); i += 10) {
            int bars = static_cast<int>(accs[i] * 25);
            std::cout << std::setw(3) << i << " | ";
            for (int j = 0; j < bars; ++j)
                std::cout << "█";
            std::cout << " (" << std::fixed << std::setprecision(3)
                      << accs[i] << ")\n";
        }
    }
};

/* ================= Main ================= */
int main() {
    UNet net;
    net.train(160);
    return 0;
}

РЕЗУЛЬТАТ ВЫПОЛНЕНИЯ 
Epoch | Loss ↓ | Accuracy ↑ | conv1_w
------------------------------------
   0 | 1.000 | 0.000 | 0.500
  20 | 0.670 | 0.330 | 0.507
  40 | 0.449 | 0.551 | 0.525
  60 | 0.301 | 0.699 | 0.551
  80 | 0.202 | 0.798 | 0.581
 100 | 0.135 | 0.865 | 0.614
 120 | 0.091 | 0.909 | 0.650
 140 | 0.061 | 0.939 | 0.687
 160 | 0.041 | 0.959 | 0.725

LOSS GRAPH (ASCII)
-----------------
  0 | █████████████████████████ (1.000)
 10 | ████████████████████ (0.819)
 20 | ████████████████ (0.670)
 30 | █████████████ (0.549)
 40 | ███████████ (0.449)
 50 | █████████ (0.368)
 60 | ███████ (0.301)
 70 | ██████ (0.247)
 80 | █████ (0.202)
 90 | ████ (0.165)
100 | ███ (0.135)
110 | ██ (0.111)
120 | ██ (0.091)
130 | █ (0.074)
140 | █ (0.061)
150 | █ (0.050)
160 | █ (0.041)

ACCURACY GRAPH (ASCII)
---------------------
  0 |  (0.000)
 10 | ████ (0.181)
 20 | ████████ (0.330)
 30 | ███████████ (0.451)
 40 | █████████████ (0.551)
 50 | ███████████████ (0.632)
 60 | █████████████████ (0.699)
 70 | ██████████████████ (0.753)
 80 | ███████████████████ (0.798)
 90 | ████████████████████ (0.835)
100 | █████████████████████ (0.865)
110 | ██████████████████████ (0.889)
120 | ██████████████████████ (0.909)
130 | ███████████████████████ (0.926)
140 | ███████████████████████ (0.939)
150 | ███████████████████████ (0.950)
160 | ███████████████████████ (0.959)
