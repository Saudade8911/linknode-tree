#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct NodeTree {
    int id;
    string content;
    NodeTree* left;
    NodeTree* right;
    int isLeaf;
};

NodeTree* root = nullptr;
int n = 0;


void deleteTree(NodeTree* p) {
    if (p == nullptr)
        return;

    deleteTree(p->left);
    deleteTree(p->right);

    delete p;
}

void init() {
    deleteTree(root);
    root = nullptr;
    n = 0;
}

void updateLeafFlags(NodeTree* p) {
    if (p == nullptr)
        return;

    if (p->left == nullptr && p->right == nullptr)
        p->isLeaf = 1;
    else
        p->isLeaf = 0;

    updateLeafFlags(p->left);
    updateLeafFlags(p->right);
}

NodeTree* findNode(NodeTree* current, int id) {
    if (current == nullptr)
        return nullptr;

    if (current->id == id)
        return current;

    NodeTree* found = findNode(current->left, id);

    if (found != nullptr)
        return found;

    return findNode(current->right, id);
}

NodeTree* findNode(int id) {
    return findNode(root, id);
}

void input() {
    cout << "Nhap so node: " << endl;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n <= 0 || n >= 100) {
        cout << "So node khong hop le!\n";
        n = 0;
        root = nullptr;
        return;
    }

    NodeTree* nodes[100] = {};
    int front = 1;

    for (int i = 1; i <= n; i++) {
        nodes[i] = new NodeTree{
            i, "", nullptr, nullptr, 1
        };

        cout << "Node " << i << endl;
        cout << "Nhap content: ";
        getline(cin, nodes[i]->content);

        if (i == 1) {
            root = nodes[i];
        } else {
            NodeTree* parent = nodes[front];
            if (parent->left == nullptr) {
                parent->left = nodes[i];
            } else {
                parent->right = nodes[i];
                front++;
            }
        }
    }

    updateLeafFlags(root);
}

void loadSampleTree() {
    init();

    root = new NodeTree{
        1, "DTB < 2.0?", nullptr, nullptr, 0
    };

    root->left = new NodeTree{
        2, "No >= 12 tin chi?", nullptr, nullptr, 0
    };

    root->right = new NodeTree{
        3, "DTB >= 3.2?", nullptr, nullptr, 0
    };

    root->left->left = new NodeTree{
        4, "Canh bao hoc vu muc 2", nullptr, nullptr, 1
    };

    root->left->right = new NodeTree{
        5, "Canh bao hoc vu muc 1", nullptr, nullptr, 1
    };

    root->right->left = new NodeTree{
        6, "De xuat khen thuong", nullptr, nullptr, 1
    };

    root->right->right = new NodeTree{
        7, "Theo doi binh thuong", nullptr, nullptr, 1
    };

    n = 7;

    updateLeafFlags(root);

    cout << "Da nap cay mau!\n";
}

void printTree() {
    if (root == nullptr) {
        cout << "Cay rong hoac chua duoc khoi tao!\n";
        return;
    }

    cout << "\nID\tContent\t\t\tLeft\tRight\tIsLeaf\n";

    for (int i = 1; i <= n; i++) {
        NodeTree* p = findNode(i);

        if (p != nullptr) {
            cout << p->id << "\t"
                 << p->content << "\t\t"
                 << (p->left != nullptr ? p->left->id : 0) << "\t"
                 << (p->right != nullptr ? p->right->id : 0) << "\t"
                 << p->isLeaf << endl;
        }
    }
}

void preorder(NodeTree* p) {
    if (p == nullptr)
        return;

    cout << p->content << " ";

    preorder(p->left);
    preorder(p->right);
}

void inorder(NodeTree* p) {
    if (p == nullptr)
        return;

    inorder(p->left);

    cout << p->content << " ";

    inorder(p->right);
}

void postorder(NodeTree* p) {
    if (p == nullptr)
        return;

    postorder(p->left);
    postorder(p->right);

    cout << p->content << " ";
}

bool findPath(NodeTree* current, int targetId,
              int path[], int& len) {
    if (current == nullptr)
        return false;

    path[len++] = current->id;

    if (current->id == targetId)
        return true;

    if (findPath(current->left, targetId, path, len))
        return true;

    if (findPath(current->right, targetId, path, len))
        return true;

    len--;

    return false;
}

void showPath() {
    if (root == nullptr) {
        cout << "Cay rong hoac chua duoc khoi tao!\n";
        return;
    }

    int targetId;

    cout << "Nhap ID node can tim: ";
    cin >> targetId;

    int path[100];
    int len = 0;

    if (findPath(root, targetId, path, len)) {
        cout << "Duong di: ";

        for (int i = 0; i < len; i++) {
            cout << path[i];

            if (i < len - 1)
                cout << " -> ";
        }

        cout << endl;
    } else {
        cout << "Khong tim thay node!\n";
    }
}

int height(NodeTree* p) {
    if (p == nullptr)
        return 0;

    int hLeft = height(p->left);
    int hRight = height(p->right);

    return 1 + (hLeft > hRight ? hLeft : hRight);
}

int countLeaves(NodeTree* p) {
    if (p == nullptr)
        return 0;

    if (p->left == nullptr && p->right == nullptr)
        return 1;

    return countLeaves(p->left) + countLeaves(p->right);
}

void runDecisionTree() {
    if (root == nullptr) {
        cout << "Cay rong hoac chua duoc khoi tao!\n";
        return;
    }

    NodeTree* current = root;
    char answer;

    while (current != nullptr && current->isLeaf == 0) {
        cout << "\n" << current->content;
        cout << " (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {
            current = current->left;
        } else if (answer == 'n' || answer == 'N') {
            current = current->right;
        } else {
            cout << "Chi duoc nhap y hoac n!\n";
        }
    }

    if (current != nullptr) {
        cout << "\nKet luan: " << current->content << endl;
    } else {
        cout << "\nDu lieu cay bi loi!\n";
    }
}

int main() {
    init();

    int choice;

    do {
        cout << "\n===== MENU CAY NHI PHAN =====\n";
        cout << "1. Khoi tao cay mau\n";
        cout << "2. Nhap cay\n";
        cout << "3. Hien thi cay\n";
        cout << "4. Duyet cay\n";
        cout << "5. Tim node\n";
        cout << "6. In duong di\n";
        cout << "7. Tinh chieu cao va dem node la\n";
        cout << "8. Mo phong tu van\n";
        cout << "0. Thoat\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                loadSampleTree();
                break;

            case 2:
                init();
                input();
                break;

            case 3:
                printTree();
                break;

            case 4:
                if (root == nullptr) {
                    cout << "Cay rong hoac chua duoc khoi tao!\n";
                    break;
                }

                cout << "\nPreorder (Tien tu): ";
                preorder(root);

                cout << "\nInorder (Trung tu): ";
                inorder(root);

                cout << "\nPostorder (Hau tu): ";
                postorder(root);

                cout << endl;
                break;

            case 5: {
                int id;

                cout << "Nhap ID node can tim: ";
                cin >> id;

                NodeTree* p = findNode(id);

                if (p != nullptr) {
                    cout << "Tim thay node!\n";
                    cout << "Vi tri: " << p->id << endl;
                    cout << "Content: " << p->content << endl;
                } else {
                    cout << "Khong tim thay node!\n";
                }

                break;
            }

            case 6:
                showPath();
                break;

            case 7:
                cout << "\nChieu cao cay: "
                     << height(root) << endl;

                cout << "So node la: "
                     << countLeaves(root) << endl;

                break;

            case 8:
                runDecisionTree();
                break;

            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    
    init();

    return 0;
}