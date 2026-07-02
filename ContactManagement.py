# Project     : Contact Management System
# Description : A simple command-line contact book that lets you
#               add, view, search, update, and delete contacts.
#               Contacts are stored in a plain text file (data.txt)
#               using comma-separated values.
# Author      : Md. Rony Ahmmed Shah
# GitHub      : github.com/Rony7s
#
# Note: To keep this beginner-friendly, contact fields (name, phone,
# address) should NOT contain commas, since commas are used to
# separate the fields in the data file.

import csv
import os

FILE_NAME = "data.txt"


def create_file():
    """Creates data.txt with a header row if it doesn't already exist."""
    if not os.path.exists(FILE_NAME):
        with open(FILE_NAME, "w", newline="", encoding="utf-8") as f:
            writer = csv.writer(f)
            writer.writerow(["Name", "Phone", "Address"])


def add_contact():
    name = input("Name    : ")
    phone = input("Phone   : ")
    address = input("Address : ")

    with open(FILE_NAME, "a", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow([name, phone, address])

    print("\nContact Added Successfully!\n")


def show_contacts():
    with open(FILE_NAME, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        next(reader, None)  # skip header row

        print("\n================ CONTACT LIST ================\n")

        found = False
        for row in reader:
            if len(row) < 3:
                continue  # skip badly formed rows

            found = True
            print(f"Name    : {row[0]}")
            print(f"Phone   : {row[1]}")
            print(f"Address : {row[2]}")
            print("--------------------------------")

        if not found:
            print("No contacts found.")

        print()


def search_contact():
    phone = input("Enter Phone Number: ")

    with open(FILE_NAME, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        next(reader, None)  # skip header row

        for row in reader:
            if len(row) >= 3 and row[1] == phone:
                print("\nContact Found")
                print("---------------------")
                print("Name    :", row[0])
                print("Phone   :", row[1])
                print("Address :", row[2])
                print()
                return

    print("\nContact Not Found!\n")


def update_contact():
    phone = input("Enter Phone Number to Update: ")
    rows = []
    updated = False

    with open(FILE_NAME, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        rows.append(next(reader))  # keep header row

        for row in reader:
            if len(row) >= 3 and row[1] == phone:
                print("\nEnter New Information")
                name = input("Name    : ")
                new_phone = input("Phone   : ")
                address = input("Address : ")

                rows.append([name, new_phone, address])
                updated = True
            else:
                rows.append(row)

    with open(FILE_NAME, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerows(rows)

    if updated:
        print("\nContact Updated Successfully!\n")
    else:
        print("\nContact Not Found!\n")


def delete_contact():
    phone = input("Enter Phone Number to Delete: ")
    rows = []
    deleted = False

    with open(FILE_NAME, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        rows.append(next(reader))  # keep header row

        for row in reader:
            if len(row) >= 3 and row[1] == phone:
                deleted = True  # skip adding this row = delete it
            else:
                rows.append(row)

    with open(FILE_NAME, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerows(rows)

    if deleted:
        print("\nContact Deleted Successfully!\n")
    else:
        print("\nContact Not Found!\n")


def show_menu():
    print("========== CONTACT MANAGEMENT ==========")
    print("1. Add Contact")
    print("2. Show All Contacts")
    print("3. Search Contact")
    print("4. Update Contact")
    print("5. Delete Contact")
    print("6. Exit")


def main():
    create_file()

    while True:
        show_menu()
        choice = input("\nEnter Choice: ")

        if choice == "1":
            add_contact()
        elif choice == "2":
            show_contacts()
        elif choice == "3":
            search_contact()
        elif choice == "4":
            update_contact()
        elif choice == "5":
            delete_contact()
        elif choice == "6":
            print("\nThank You!\n")
            break
        else:
            print("\nInvalid Choice!\n")


if __name__ == "__main__":
    main()
