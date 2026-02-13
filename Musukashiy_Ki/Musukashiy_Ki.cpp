//ПАНОВА АНАСТАСИЯ БАС-2
#include <iostream>
//#include <fstream>
#include <locale>
using namespace std;

const int n = 2;
const int nn = 4;
struct item;    // прототип структуры

struct page{    // страница
    short m;	// число элементов на странице
    page* p0;	// указатель на левую страницу-потомка
    item* e[nn];// массив указателей на элементы
};

struct item{    //
    long int key;   // ключ
    page* p;	// указатель на правую страницу-потомка
    long int count; // число элементов с данным ключом
};

/*
{
    if (a == NULL){ //D нет в дереве, включение
        (*V).d = D;
        (*V).p = NULL;
        Rost = 1;
    }
    else{ //Поиск в Б-дереве (D,a)
        if ((R > 0) && ((*a).er.data = D)) // элемент D есть в дереве
        else //Построение Б-дерева (D, a→eR.p, Rost, u)
            {
            if (Rost == 1){ //включение u вправо от eR
                if ((*a).k < 2*m){
                    Rost = 0;
                    (*a).k = (*a).k + 1;
                    for (int i = (*a).k; i > R+2; i--) (*a).ei == (*a).ei - 1;
                    (*a).e R+1 = u;
                }
                else{ // переполнение страницы
                    new(b) //создание новой страницы
                    if (R <= m) V = u;
                    else {
                        V = (*a).em;
                        for (int i = m; i > R+2; i--) (*a).ei = (*a).ei - 1;
                        (*a).eR+1 = u;
                    }
                    for ( int i = 1; i < m; i++) (*b).ei = (*a).ei +1;
                }
            }
            else{ //включение в правую страницу
                R = R - m;
                V = em +1;
                for (int i = 1; i < R-1; i++) (*b).ei = (*b).ei + m + 1;
                (*b).eR = u;
                for (int i = R+1; i < m; i++) (*b).ei = (*a).ei + m;
            }
            (*a).k = m;
            (*b).k = m;
            (*b)p0 = V.p;
            V.p = b;
        }
    }
}
*/

void search(long int x, item*& a, bool h, item* v) {//ПОИСК КЛЮЧА Х В Б-ДЕРЕВЕ
    long int k, L, r;
    item* q, u, b;
    long int i;
    if (a == NULL) {
        (*item).key = x;
        (*item).p = NULL;
        (*item).count = 1;
    }
    else {
        L = 1, r = m;
        do {
            k = (L + r)\\2; 
            if (x <= e[k].key) r = k - 1;
            if (x >= e[k].key) L = k + 1;
        } while (r < L);
        if ((L - r) > 1){
            e[k].count = e[k].count + 1;
            h = 0;
        }
        else {
            if (r == 0) q = p0;
            else q = e[r].p;
        }
        search(x, q, h, u);
    }
    //ВСТАВКА ЭЛЕМЕНТА на уровне конкретной вершины
    if (h == 1) {
        if (m < nn) {
            m = m + 1;
            h = 0;
            for (i = m; i < r + 2; i++) e[i] = e[i - 1];
            e[r + 1] = u;
        }
        else {
            new (b);
            if (r <= n) {
                if (r == n) v = u;
                else {
                    v = e[n];
                    for (i = 1; i < n; i++) e[i] = e[i - 1];
                    e[r + 1] = u;
                }
                for (i = 1; i < n; i++) b^.e[i] = a^.e[i - 1];
            }
            else {
                r = r - n; v = e[n + 1];
                for (i = 1; i < r - 1; i++) b^ .e[i] = a ^ .e[i + n + 1];
                b^ .e[r] = u;
                for (i = r + 1; i < n; i++) b^ .e[i] = a ^ .e[i + n];
            }
            m = n;
            b^ .m = n;
            b^ .p0 = v.p;
            (*v).p = b;
        }
    }
}//конец процедуры search «ПОИСК КЛЮЧА Х В Б-ДЕРЕВЕ»

void printtree(item* p, long int L) {
    long int i;
    if (p != NULL) {
        cout << "m = " << m;
        for (i = 1; i < l; ++) cout << " ";
        for (i = 1; i < m; ++) cout << e[i].key:4;
        cout << endl;
        printtree(p0, L + 1);
        for (i = 1; i < m; ++) printtree(e[i].p, L + 1);
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    long int x;
    item* root = NULL;
    cout << "Введите ключ: "; cin >> x;
    while (x != 0) {
        search(x, root, h, u);
        if (h == 1) {
            item* q = root;
            *root = new item;
            (*root).m = 1;
            (*root).p0 = q;
            e[1] = u;
        }
        cout << "Б-дерево: " << endl;
        printtree(root, 1);
        cout << "Введите ключ: "; cin >> x;
    }
    //ifstream f; //главный файл открывается для чтения
    //f.open("Ki.txt");
    //Ki* el = NULL;
    //int a = 0;
    //f >> a;
    //Atarashii_Ki(el, a); R = el;// Создание корня
    //while (!f.eof()) {
    //    f >> a;
    //    Atarashii_Ha(R, a);// Добаление листа
    //    print_massugu(R); cout << endl;
    //    H_ovari(R);// Пересчёт баланса
    //}
    //cout << "Вывод перед завершением программы: " << endl;
    //print_subete(R);// Полный баланс
    return 0;
}