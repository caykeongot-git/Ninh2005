#include <bits/stdc++.h>
using namespace std;

typedef struct NODE{
    int heSo;
    int soMu;
    struct NODE* next;
}NODE;

typedef struct DATHUC{
    NODE* head;
    NODE* tail;
}DATHUC;

void Init(DATHUC &dt){
    dt.head = dt.tail = NULL;
}

bool IsEmpty(DATHUC dt){
    return dt.head == NULL;
}

void DeleteDATHUC(DATHUC &dt){
    while(dt.head != NULL){
        NODE* temp = dt.head;
        dt.head = dt.head->next;
        delete temp;
    }
    dt.tail = NULL;
}

void ShowDATHUC(DATHUC &dt){
    if(IsEmpty(dt)){
        cout << "Da thuc rong !!!" << endl;
        return;
    }
    NODE* temp = dt.head;
    while(temp != NULL){
        cout << temp->heSo << "x^" << temp->soMu;
        if(temp->next != NULL) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

NODE* CreateNode(int heSo, int soMu){
    NODE* newNode = new NODE;
    if(newNode == NULL){
        cout << "Cap phat bo nho khong thanh cong !!!" << endl;
        exit(0);
    }
    newNode->heSo = heSo;
    newNode->soMu = soMu;
    newNode->next = NULL;
    return newNode;
}

void Push_Back(DATHUC &dt, int heSo, int soMu){
    NODE* newNode = CreateNode(heSo, soMu);
    if(IsEmpty(dt)) dt.head = dt.tail = newNode;
    else{
        dt.tail->next = newNode;
        dt.tail = newNode;
    }
}

double CALC(DATHUC dt, int x){
    double res = 0;
    for(NODE* i=dt.head; i!=NULL; i=i->next){
        res+=i->heSo*pow(x, i->soMu);
    }
    return res;
}

//Viết hàm chèn đơn thức vào sau đơn thức có số mũ lẻ đầu tiên, nếu không có chèn vào đầu đa thức.
void Insert(DATHUC &dt, int heSo, int soMu){
    NODE* newNode = CreateNode(heSo, soMu);
    bool check = 0;
    for(NODE* i=dt.head; i!=NULL; i=i->next){
        if(i->soMu % 2 != 0){
            newNode->next = i->next;
            i->next = newNode;
            check = 1;
            break;
        }
    }
    if(!check){
        newNode->next = dt.head;
        dt.head = newNode;
        if (dt.tail == NULL) dt.tail = newNode;
    }
}

// Viết hàm tìm node có giá trị lớn nhất tính theo x, trả về giá trị đó 
int TimMaxValue(DATHUC dt, int x){
    long long value = 0;
    long long max = INT_MIN;
    for(NODE* i=dt.head; i!=NULL; i=i->next){
        long long temp = i->heSo*pow(x, i->soMu);
        if(temp > max){
            max = temp;
            value = i->heSo;
        }
    }
    return value;
}

// Mô tả thuật toán tìm bậc cao nhất (TimBacMax) để tìm đơn thức có bậc cao nhất trong đa thức P(x)
int TimMaxBac(DATHUC dt){
    int max = INT_MIN;
    for(NODE* i=dt.head; i!=NULL; i=i->next){
        if(i->soMu > max) max = i->soMu;
    }
    return max;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    DATHUC dt;
    Init(dt);
    cout << "Nhap vao he so va so mu (Nhap 0 0 de dung nhap)" << endl;
    while(true){
        int heSo, soMu; cin >> heSo >> soMu;
        if(heSo == 0 && soMu == 0) break; 
        Push_Back(dt, heSo, soMu);
        ShowDATHUC(dt);
    }
    cout << "Nhap vao x: " << flush;
    int x; cin >> x;
    cout << "Gia tri cua da thuc theo x = " << CALC(dt, x) << endl;
    // cout << "Nhap don thuc can chen: " << flush;
    // int heSo, soMu; cin >> heSo >> soMu;
    // Insert(dt, heSo, soMu);
    // cout << "Da thuc sau khi chen them don thuc: ";
    // ShowDATHUC(dt);
    cout << "Nhap vao y: " << flush;
    int y; cin >> y;
    cout << "Gia tri theo y lon nhat trong da thuc la = " << TimMaxValue(dt, y) << endl;
    cout << "Bac lon nhat trong da thuc la = " << TimMaxBac(dt) << endl;
    DeleteDATHUC(dt);
    return 0;
}