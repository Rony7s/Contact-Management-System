/*
 * Project     : Contact Management System
 * Description : A simple command-line contact book that lets you
 *               add, view, search, update, and delete contacts.
 *               Contacts are stored in a plain text file (data.txt)
 *               using comma-separated values.
 * Author      : Md. Rony Ahmmed Shah
 * GitHub      : github.com/Rony7s
 *
 * Note: To keep this beginner-friendly, contact fields (name, phone,
 * address) should NOT contain commas, since commas are used to
 * separate the fields in the data file.
 */

import java.io.*;
import java.util.*;

public class ContactManagement {

    static final String FILE_NAME = "data.txt";
    static Scanner sc = new Scanner(System.in);

    // Creates data.txt with a header row if it doesn't already exist.
    static void createFile() {
        try {
            File file = new File(FILE_NAME);

            if (!file.exists()) {
                file.createNewFile();

                BufferedWriter bw = new BufferedWriter(new FileWriter(file));
                bw.write("Name,Phone,Address");
                bw.newLine();
                bw.close();
            }

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void addContact() {
        try {
            System.out.print("Name    : ");
            String name = sc.nextLine();

            System.out.print("Phone   : ");
            String phone = sc.nextLine();

            System.out.print("Address : ");
            String address = sc.nextLine();

            BufferedWriter bw = new BufferedWriter(new FileWriter(FILE_NAME, true));
            bw.write(name + "," + phone + "," + address);
            bw.newLine();
            bw.close();

            System.out.println("\nContact Added Successfully!\n");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void showContacts() {
        try {
            BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
            br.readLine(); // skip header row

            System.out.println("\n========== CONTACT LIST ==========\n");

            String line;
            boolean found = false;

            while ((line = br.readLine()) != null) {
                String[] data = line.split(",", -1);
                if (data.length < 3) continue; // skip badly formed rows

                System.out.println("Name    : " + data[0]);
                System.out.println("Phone   : " + data[1]);
                System.out.println("Address : " + data[2]);
                System.out.println("--------------------------------");

                found = true;
            }

            if (!found)
                System.out.println("No contacts found.");

            br.close();

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void searchContact() {
        System.out.print("Enter Phone Number: ");
        String phone = sc.nextLine();

        try {
            BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
            br.readLine(); // skip header row

            String line;

            while ((line = br.readLine()) != null) {
                String[] data = line.split(",", -1);
                if (data.length < 3) continue;

                if (data[1].equals(phone)) {
                    System.out.println("\nContact Found");
                    System.out.println("-----------------------");
                    System.out.println("Name    : " + data[0]);
                    System.out.println("Phone   : " + data[1]);
                    System.out.println("Address : " + data[2]);
                    br.close();
                    return;
                }
            }

            br.close();
            System.out.println("\nContact Not Found!\n");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void updateContact() {
        System.out.print("Enter Phone Number to Update: ");
        String phone = sc.nextLine();

        try {
            BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
            ArrayList<String> rows = new ArrayList<>();
            boolean updated = false;

            rows.add(br.readLine()); // keep header row

            String line;

            while ((line = br.readLine()) != null) {
                String[] data = line.split(",", -1);

                if (data.length >= 3 && data[1].equals(phone)) {
                    System.out.println("\nEnter New Information");

                    System.out.print("Name    : ");
                    String newName = sc.nextLine();

                    System.out.print("Phone   : ");
                    String newPhone = sc.nextLine();

                    System.out.print("Address : ");
                    String newAddress = sc.nextLine();

                    rows.add(newName + "," + newPhone + "," + newAddress);
                    updated = true;

                } else {
                    rows.add(line);
                }
            }

            br.close();

            BufferedWriter bw = new BufferedWriter(new FileWriter(FILE_NAME));
            for (String row : rows) {
                bw.write(row);
                bw.newLine();
            }
            bw.close();

            if (updated)
                System.out.println("\nContact Updated Successfully!\n");
            else
                System.out.println("\nContact Not Found!\n");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void deleteContact() {
        System.out.print("Enter Phone Number to Delete: ");
        String phone = sc.nextLine();

        try {
            BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
            ArrayList<String> rows = new ArrayList<>();
            boolean deleted = false;

            rows.add(br.readLine()); // keep header row

            String line;

            while ((line = br.readLine()) != null) {
                String[] data = line.split(",", -1);

                if (data.length >= 3 && data[1].equals(phone)) {
                    deleted = true; // skip adding this row = delete it
                } else {
                    rows.add(line);
                }
            }

            br.close();

            BufferedWriter bw = new BufferedWriter(new FileWriter(FILE_NAME));
            for (String row : rows) {
                bw.write(row);
                bw.newLine();
            }
            bw.close();

            if (deleted)
                System.out.println("\nContact Deleted Successfully!\n");
            else
                System.out.println("\nContact Not Found!\n");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void showMenu() {
        System.out.println("========== CONTACT MANAGEMENT ==========");
        System.out.println("1. Add Contact");
        System.out.println("2. Show All Contacts");
        System.out.println("3. Search Contact");
        System.out.println("4. Update Contact");
        System.out.println("5. Delete Contact");
        System.out.println("6. Exit");
        System.out.print("\nEnter Choice: ");
    }

    public static void main(String[] args) {
        createFile();

        while (true) {
            showMenu();

            int choice;
            try {
                choice = Integer.parseInt(sc.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("\nInvalid Choice!\n");
                continue;
            }

            switch (choice) {
                case 1: addContact(); break;
                case 2: showContacts(); break;
                case 3: searchContact(); break;
                case 4: updateContact(); break;
                case 5: deleteContact(); break;
                case 6:
                    System.out.println("\nThank You!");
                    return;
                default:
                    System.out.println("\nInvalid Choice!\n");
            }
        }
    }
}
