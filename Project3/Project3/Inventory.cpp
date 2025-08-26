#include <iostream>
using namespace std;

template <typename T>
class Inventory {
private:
    T* pItems_;       // 아이템들을 저장할 동적 배열
    int capacity_;    // 인벤토리 최대 용량
    int size_;        // 현재 저장된 아이템 개수

public:
    // 생성자
    Inventory(int capacity = 10)
        : capacity_(capacity > 0 ? capacity : 1), size_(0) {
        pItems_ = new T[capacity_];   
    }

    // 소멸자
    ~Inventory() {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    // 아이템 추가
    void AddItem(const T& item) {
        if (size_ < capacity_) {
            pItems_[size_] = item;
            size_++;
        }
        else {
            cout << "인벤토리가 꽉 찼습니다!" << endl;
        }
    }

    // 마지막 아이템 제거
    void RemoveLastItem() {
        if (size_ > 0) {
            size_--;
        }
        else {
            cout << "인벤토리가 비어있습니다." << endl;
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
            cout << "(비어있음)" << endl;
            return;
        }
        for (int i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
    }
};

// ==============================
// 아이템 계열 클래스들
// ==============================

// 기본 아이템 클래스
class Item {
private:
    string name_;
    int price_;
public:
    Item(const string& name = "Unknown", int price = 0)
        : name_(name), price_(price) {}

    void PrintInfo() const {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }
};

// 무기 클래스
class Weapon {
private:
    string name_;
    int damage_;
    int price_;
public:
    Weapon(const string& name = "Sword", int damage = 10, int price = 100)
        : name_(name), damage_(damage), price_(price) {}

    void PrintInfo() const {
        cout << "[무기: " << name_
            << ", 공격력: " << damage_
            << ", 가격: " << price_ << "G]" << endl;
    }
};

// 물약 클래스
class Potion {
private:
    string name_;
    int heal_;
    int price_;
public:
    Potion(const string& name = "Potion", int heal = 50, int price = 30)
        : name_(name), heal_(heal), price_(price) {}

    void PrintInfo() const {
        cout << "[물약: " << name_
            << ", 회복량: " << heal_
            << ", 가격: " << price_ << "G]" << endl;
    }
};

int main() {
    // Item 타입 인벤토리
    Inventory<Item> itemInventory(5);
    itemInventory.AddItem(Item("돌", 1));
    itemInventory.AddItem(Item("나무막대기", 5));
    itemInventory.PrintAllItems();

    cout << "------------------" << endl;

    // Weapon 타입 인벤토리
    Inventory<Weapon> weaponInventory(3);
    weaponInventory.AddItem(Weapon("검", 15, 120));
    weaponInventory.AddItem(Weapon("활", 20, 200));
    weaponInventory.PrintAllItems();

    cout << "------------------" << endl;

    // Potion 타입 인벤토리
    Inventory<Potion> potionInventory(2);
    potionInventory.AddItem(Potion("HP 포션", 100, 50));
    potionInventory.PrintAllItems();
    potionInventory.RemoveLastItem();
    potionInventory.PrintAllItems();

    return 0;
}
