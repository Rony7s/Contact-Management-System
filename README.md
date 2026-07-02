# 📒 Contact Book — Multi-Language CLI (C / C++ / Java / Python)

A beginner-friendly **Contact Management System** implemented in four
languages side by side, so you can compare how the same program looks
in **C**, **C++**, **Java**, and **Python**.

It's built around one goal: teach **file handling** and **CRUD
operations** (Create, Read, Update, Delete) using nothing but a plain
text file — no database required.

> Great for students who are learning a language and want a small,
> complete project to study — or for comparing how the same logic
> is expressed differently across languages.

---

## 👨‍💻 Author

**Md. Rony Ahmmed Shah**
- 🌐 GitHub: https://github.com/Rony7s

If this project helps you learn something, consider giving it a ⭐.

---

## 🚀 Available Languages

| Language | File |
|---|---|
| ✅ C | `ContactManagement.c` |
| ✅ C++ | `ContactManagement.cpp` |
| ✅ Java | `ContactManagement.java` |
| ✅ Python | `ContactManagement.py` |

All four versions implement the exact same menu and features, so you
can open two side by side and compare how each language handles
files, strings, and loops.

---

## 📌 Features

- Auto-creates `data.txt` on first run
- Add a contact
- Show all contacts
- Search a contact by phone number
- Update a contact
- Delete a contact
- Simple, menu-driven console interface
- Clear, commented, beginner-friendly source code

---

## 📂 Project Structure

```
ContactManagement/
│
├── ContactManagement.c
├── ContactManagement.cpp
├── ContactManagement.java
├── ContactManagement.py
├── data.txt
└── README.md
```

---

## 📄 Data Storage

All contacts are stored as plain comma-separated values in `data.txt`:

```
Name,Phone,Address
Ronnie,01706373000,Rajshahi Bangladesh
```

> ⚠️ **Beginner note:** this format is simple on purpose. Since a
> comma separates each field, a name or address that contains a
> comma will break the parsing. That's a normal trade-off for a
> learning project — a real app would use a proper CSV library with
> quoting, or a database. (The Python version already uses Python's
> built-in `csv` module, which is a nice example of that upgrade
> path.)

All four language versions read and write this **same plain format**,
so you can freely switch between them on the same `data.txt` file.

---

## 📖 Menu

```
========== CONTACT MANAGEMENT ==========

1. Add Contact
2. Show All Contacts
3. Search Contact
4. Update Contact
5. Delete Contact
6. Exit
```

---

## ▶️ How to Run

### C
```bash
gcc ContactManagement.c -o ContactManagement
./ContactManagement        # Windows: ContactManagement.exe
```

### C++
```bash
g++ ContactManagement.cpp -o ContactManagement
./ContactManagement        # Windows: ContactManagement.exe
```

### Java
```bash
javac ContactManagement.java
java ContactManagement
```

### Python
```bash
python3 ContactManagement.py
```

---

## 📚 Concepts You'll Practice

### C
- Structs, arrays, and pointers
- `fopen` / `fgets` / `fprintf` file I/O
- `sscanf` string parsing
- Menu-driven program flow

### C++
- `fstream` / `stringstream`
- `vector<string>` for in-memory rows
- Functions and pass-by-reference
- Basic file I/O patterns used before jumping into OOP

### Java
- Classes and static methods
- `BufferedReader` / `BufferedWriter`
- `ArrayList<String>`
- try/catch exception handling

### Python
- Functions and the `csv` module
- File handling with `with open(...)`
- List comprehension-friendly data handling
- The `if __name__ == "__main__":` entry-point pattern

---

## 🎯 Learning Objectives

- Understand CRUD operations from first principles
- Read, write, and rewrite files safely
- Search and filter records
- See the *same* logic implemented in four different languages
- Compare each language's strengths and syntax for a real task

---

## 💡 Ideas to Extend This Project

- Give each contact a unique ID (instead of relying on phone number)
- Validate phone numbers (digits only, fixed length)
- Prevent duplicate phone numbers
- Search by name as well as phone
- Sort contacts alphabetically
- Switch storage to a real CSV library with quoting (C/C++/Java)
- Move storage to SQLite or another lightweight database
- Add a simple GUI (Tkinter for Python, JavaFX for Java, etc.)
- Build a REST API version (Flask/Express/Spring Boot)

These make excellent "next step" exercises once you're comfortable
with the base version.

---

## 🤝 Contributing

Contributions are welcome!

1. Fork this repository
2. Create a new branch
3. Make your changes
4. Submit a Pull Request

---

## 📜 License

This project is licensed under the **MIT License**.
Feel free to use, modify, and learn from it.

---

## ❤️ Happy Coding!

> *"The best way to learn programming is by building projects."*

Made with ❤️ by **Md. Rony Ahmmed Shah**
