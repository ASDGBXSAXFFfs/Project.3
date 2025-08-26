#include <iostream>
using namespace std;

template <typename T>
class Inventory {
private:
    T* pItems_;       // �����۵��� ������ ���� �迭
    int capacity_;    // �κ��丮 �ִ� �뷮
    int size_;        // ���� ����� ������ ����

public:
    // ������
    Inventory(int capacity = 10)
        : capacity_(capacity > 0 ? capacity : 1), size_(0) {
        pItems_ = new T[capacity_];   
    }

    // �Ҹ���
    ~Inventory() {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    // ������ �߰�
    void AddItem(const T& item) {
        if (size_ < capacity_) {
            pItems_[size_] = item;
            size_++;
        }
        else {
            cout << "�κ��丮�� �� á���ϴ�!" << endl;
        }
    }

    // ������ ������ ����
    void RemoveLastItem() {
        if (size_ > 0) {
            size_--;
        }
        else {
            cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
        }
    }

    int GetSize() const {
        return size_;
    }

    int GetCapacity() const {
        return capacity_;
    }

    void PrintAllItems() const {
        if (size_ == 0) {
            cout << "(�������)" << endl;
            return;
        }
        for (int i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
    }
};

// ==============================
// ������ �迭 Ŭ������
// ==============================

// �⺻ ������ Ŭ����
class Item {
private:
    string name_;
    int price_;
public:
    Item(const string& name = "Unknown", int price = 0)
        : name_(name), price_(price) {}

    void PrintInfo() const {
        cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
    }
};

// ���� Ŭ����
class Weapon {
private:
    string name_;
    int damage_;
    int price_;
public:
    Weapon(const string& name = "Sword", int damage = 10, int price = 100)
        : name_(name), damage_(damage), price_(price) {}

    void PrintInfo() const {
        cout << "[����: " << name_
            << ", ���ݷ�: " << damage_
            << ", ����: " << price_ << "G]" << endl;
    }
};

// ���� Ŭ����
class Potion {
private:
    string name_;
    int heal_;
    int price_;
public:
    Potion(const string& name = "Potion", int heal = 50, int price = 30)
        : name_(name), heal_(heal), price_(price) {}

    void PrintInfo() const {
        cout << "[����: " << name_
            << ", ȸ����: " << heal_
            << ", ����: " << price_ << "G]" << endl;
    }
};

int main() {
    // Item Ÿ�� �κ��丮
    Inventory<Item> itemInventory(5);
    itemInventory.AddItem(Item("��", 1));
    itemInventory.AddItem(Item("���������", 5));
    itemInventory.PrintAllItems();

    cout << "------------------" << endl;

    // Weapon Ÿ�� �κ��丮
    Inventory<Weapon> weaponInventory(3);
    weaponInventory.AddItem(Weapon("��", 15, 120));
    weaponInventory.AddItem(Weapon("Ȱ", 20, 200));
    weaponInventory.PrintAllItems();

    cout << "------------------" << endl;

    // Potion Ÿ�� �κ��丮
    Inventory<Potion> potionInventory(2);
    potionInventory.AddItem(Potion("HP ����", 100, 50));
    potionInventory.PrintAllItems();
    potionInventory.RemoveLastItem();
    potionInventory.PrintAllItems();

    return 0;
}
