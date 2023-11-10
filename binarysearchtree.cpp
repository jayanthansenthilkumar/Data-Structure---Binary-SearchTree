#include<iostream>
#include<stdlib.h>
void insert(int, int);
void delte(int);
void display(int);
int search(int);
int search1(int, int);
int tree[40], t = 1, x, i;
int main() {
    int ch, y;
    for (i = 1; i < 40; i++) {
        tree[i] = -1;
    }
    while (1) {
        std::cout << "1. INSERT\n2. DELETE\n3. DISPLAY\n4. SEARCH\n5. EXIT\nEnter your choice:";
        std::cin >> ch;

        switch (ch) {
        case 1:
            std::cout << "Enter the element to insert: ";
            std::cin >> ch;
            insert(1, ch);
            break;
        case 2:
            std::cout << "Enter the element to delete: ";
            std::cin >> x;
            y = search(1);
            if (y != -1)
                delte(y);
            else
                std::cout << "No such element in tree" << std::endl;
            break;
        case 3:
            display(1);
            std::cout << "\n";
            break;
        case 4:
            std::cout << "Enter the element to search: ";
            std::cin >> x;
            y = search(1);
            if (y == -1)
                std::cout << "No such element in tree" << std::endl;
            else
                std::cout << x << " is in position " << y << std::endl;
            break;
        case 5:
            exit(0);
        }
    }
}
void insert(int s, int ch) {
    int x;
    if (t == 1) {
        tree[t++] = ch;
        return;
    }
    x = search1(s, ch);
    if (tree[x] > ch)
        tree[2 * x] = ch;
    else
        tree[2 * x + 1] = ch;
    t++;
}
void delte(int x) {
    if (tree[2 * x] == -1 && tree[2 * x + 1] == -1)
        tree[x] = -1;
    else if (tree[2 * x] == -1) {
        tree[x] = tree[2 * x + 1];
        tree[2 * x + 1] = -1;
    } else if (tree[2 * x + 1] == -1) {
        tree[x] = tree[2 * x];
        tree[2 * x] = -1;
    } else {
        tree[x] = tree[2 * x];
        delte(2 * x);
    }
    t--;
}
int search(int s) {
    if (t == 1) {
        std::cout << "No element in tree" << std::endl;
        return -1;
    }
    if (tree[s] == -1)
        return tree[s];
    if (tree[s] > x)
        return search(2 * s);
    else if (tree[s] < x)
        return search(2 * s + 1);
    else
        return s;
}
void display(int s) {
    if (t == 1) {
        std::cout << "No element in tree" << std::endl;
        return;
    }
    for (int i = 1; i < 40; i++) {
        if (tree[i] == -1)
            std::cout << " ";
        else
            std::cout << tree[i];
    }
    std::cout << std::endl;
}
int search1(int s, int ch) {
    if (t == 1) {
        std::cout << "No element in tree" << std::endl;
        return -1;
    }
    if (tree[s] == -1)
        return s / 2;
    if (tree[s] > ch)
        return search1(2 * s, ch);
    else
        return search1(2 * s + 1, ch);
}
