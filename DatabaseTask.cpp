#include <iostream>
#include <map>
#include <memory>
#include <string>

struct Student {
    int id;
    std::string name;
    int age;
};

class StudentDatabase {
private:
    std::map<int, std::shared_ptr<Student>> database;

public:
    void addStudent(int id, const std::string& name, int age) {
        auto student = std::make_shared<Student>();
        student->id = id;
        student->name = name;
        student->age = age;
        database[id] = student;
    }

    void removeStudent(int id) {
        database.erase(id);
    }

    std::shared_ptr<Student> getStudent(int id) {
        auto it = database.find(id);
        if (it != database.end()) {
            return it->second;
        }
        else {
            return nullptr; 
        }
    }
};

int main() {
    StudentDatabase db;

    // Добавление студентов
    db.addStudent(1, "Rauf", 20);
    db.addStudent(2, "Ivan", 22);

    // Получение информации о студенте по идентификатору
    auto student = db.getStudent(1);
    if (student) {
        std::cout << "Student found: " << student->name << ", Age: " << student->age << std::endl;
    }
    else {
        std::cout << "Student not found." << std::endl;
    }

    // Удаление студента
    db.removeStudent(2);

    return 0;
}
