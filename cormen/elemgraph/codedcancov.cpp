#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// ====================== Representation ======================

using AttrSet = set<char>;

struct FD {
    AttrSet lhs;
    AttrSet rhs; // will store single attribute after splitting
};

// ====================== Utility ======================

void printAttrSet(const AttrSet& s) {
    for (char c : s) cout << c;
}

void printFDs(const vector<FD>& fds) {
    for (const FD& fd : fds) {
        printAttrSet(fd.lhs);
        cout << " -> ";
        printAttrSet(fd.rhs);
        cout << endl;
    }
}

// ====================== Closure ======================

AttrSet closure(AttrSet attrs, const vector<FD>& fds) {
    AttrSet result = attrs;

    bool changed = true;
    while (changed) {
        changed = false;

        for (const FD& fd : fds) {
            bool applicable = true;

            for (char c : fd.lhs) {
                if (result.find(c) == result.end()) {
                    applicable = false;
                    break;
                }
            }

            if (applicable) {
                for (char c : fd.rhs) {
                    if (result.insert(c).second) {
                        changed = true;
                    }
                }
            }
        }
    }

    return result;
}

// ====================== Step 1 ======================

vector<FD> splitRHS(const vector<FD>& fds) {
    vector<FD> result;

    for (const FD& fd : fds) {
        for (char c : fd.rhs) {
            result.push_back({fd.lhs, {c}});
        }
    }

    return result;
}

// ====================== Step 2 ======================

void minimizeLHS(vector<FD>& fds) {
    for (FD& fd : fds) {
        vector<char> attrs(fd.lhs.begin(), fd.lhs.end());

        for (char attr : attrs) {
            AttrSet temp = fd.lhs;
            temp.erase(attr);

            AttrSet cl = closure(temp, fds);

            if (cl.find(*fd.rhs.begin()) != cl.end()) {
                fd.lhs.erase(attr);
            }
        }
    }
}

// ====================== Step 3 ======================

void removeRedundantFDs(vector<FD>& fds) {
    for (int i = 0; i < fds.size(); ) {
        FD target = fds[i];

        vector<FD> reduced;
        for (int j = 0; j < fds.size(); j++) {
            if (i != j) reduced.push_back(fds[j]);
        }

        AttrSet cl = closure(target.lhs, reduced);

        if (cl.find(*target.rhs.begin()) != cl.end()) {
            fds.erase(fds.begin() + i);
        } else {
            i++;
        }
    }
}

// ====================== Canonical Cover ======================

vector<FD> canonicalCover(vector<FD> fds) {

    cout << "\nAfter RHS Split:\n";
    fds = splitRHS(fds);
    printFDs(fds);

    cout << "\nAfter LHS Minimization:\n";
    minimizeLHS(fds);
    printFDs(fds);

    cout << "\nAfter Removing Redundant FDs:\n";
    removeRedundantFDs(fds);
    printFDs(fds);

    return fds;
}

// ====================== Input Parser ======================

AttrSet parseAttrSet(const string& s) {
    AttrSet result;
    for (char c : s) {
        if (isalpha(c)) result.insert(c);
    }
    return result;
}

vector<FD> inputFDs() {
    int n;
    cout << "Enter number of FDs: ";
    cin >> n;

    vector<FD> fds;
    cin.ignore();

    cout << "Enter FDs in format AB->CD:\n";

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        int arrow = line.find("->");

        string lhs = line.substr(0, arrow);
        string rhs = line.substr(arrow + 2);

        fds.push_back({parseAttrSet(lhs), parseAttrSet(rhs)});
    }

    return fds;
}

// ====================== Main ======================

int main() {

    vector<FD> fds = inputFDs();

    cout << "\nOriginal FDs:\n";
    printFDs(fds);

    vector<FD> result = canonicalCover(fds);

    cout << "\nFinal Canonical Cover:\n";
    printFDs(result);

    return 0;
}