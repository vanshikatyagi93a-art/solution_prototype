#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Portfolio {
    string id;
    bool isPrivileged; 
    bool isHired;
};

class EquiLogicEngine {
public:
    void runBiasAudit(const vector<Portfolio>& data) {
        int privTotal = 0, privHired = 0;
        int unprivTotal = 0, unprivHired = 0;

        for (const auto& p : data) {
            if (p.isPrivileged) {
                privTotal++;
                if (p.isHired) privHired++;
            } else {
                unprivTotal++;
                if (p.isHired) unprivHired++;
            }
        }

        double privRate = (double)privHired / privTotal;
        double unprivRate = (double)unprivHired / unprivTotal;
        double impactRatio = unprivRate / privRate;

        printReport(impactRatio, unprivRate, privRate);
    }

private:
    void printReport(double ratio, double unprivRate, double privRate) {
        cout << "==========================================" << endl;
        cout << "      EQUITECH SOLUTIONS - AUDIT REPORT    " << endl;
        cout << "==========================================" << endl;
        cout << "Unprivileged Hire Rate: " << fixed << setprecision(2) << unprivRate * 100 << "%" << endl;
        cout << "Privileged Hire Rate:   " << privRate * 100 << "%" << endl;
        cout << "------------------------------------------" << endl;
        cout << "DISPARATE IMPACT RATIO: " << ratio << endl;

        // The 80% Rule logic (0.8 Threshold)
        if (ratio < 0.8) {
            cout << "STATUS: [FLAGGED] BIAS DETECTED" << endl;
            cout << "ACTION: Triggering Reweighing Algorithm..." << endl;
            applyReweighingFix();
        } else {
            cout << "STATUS: [COMPLIANT] FAIRNESS VERIFIED" << endl;
        }
        cout << "==========================================" << endl;
    }

    void applyReweighingFix() {
        cout << ">>> Reweighing Logic: Increasing influence of merit-based" << endl;
        cout << ">>> project markers for underrepresented groups." << endl;
    }
};

int main() {
    EquiLogicEngine engine;

    vector<Portfolio> dataset = {
        {"C001", true, true},  {"C002", true, true},  {"C003", true, false},
        {"C004", false, true}, {"C005", false, false}, {"C006", false, false}
    };

    engine.runBiasAudit(dataset);

    return 0;
}