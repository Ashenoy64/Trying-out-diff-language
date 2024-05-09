import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Contact implements Serializable {
    private static final long serialVersionUID = 1L;

    private String name;
    private String phoneNumber;
    private String email;

    public Contact(String name, String phoneNumber, String email) {
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public String getEmail() {
        return email;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Phone: " + phoneNumber + ", Email: " + email;
    }
}

public class ContactsApp {
    private static final String SAVE_FILE = "contacts.ser";

    private static List<Contact> contacts = new ArrayList<>();

    public static void main(String[] args) {
        loadContacts();

        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Welcome to Contacts App!");
            System.out.println("1. Add a new contact");
            System.out.println("2. View all contacts");
            System.out.println("3. Edit an existing contact");
            System.out.println("4. Delete an existing contact");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.println();
                    addContact(scanner);
                    System.out.println();
                    break;
                    case 2:
                    System.out.println();
                    viewAllContacts();
                    System.out.println();
                    break;
                    case 3:
                    System.out.println();
                    editContact(scanner);
                    System.out.println();
                    break;
                    case 4:
                    System.out.println();
                    deleteContact(scanner);
                    System.out.println();
                    break;
                    case 5:
                    System.out.println();
                    saveContacts();
                    System.out.println("Exiting...");
                    System.out.println();
                    break;
                    default:
                    System.out.println();
                    System.out.println("Invalid choice. Please try again.");
                    System.out.println();
            }
        } while (choice != 5);

        scanner.close();
        System.out.println();
        System.out.println();
    }

    private static void addContact(Scanner scanner) {
        System.out.print("Enter name: ");
        String name = scanner.nextLine();

        System.out.print("Enter phone number: ");
        String phoneNumber = scanner.nextLine();

        System.out.print("Enter email: ");
        String email = scanner.nextLine();

        Contact newContact = new Contact(name, phoneNumber, email);
        contacts.add(newContact);
        System.out.println("Contact added successfully!");
        System.out.println();
    }

    private static void viewAllContacts() {
        System.out.println("Contacts:");
        for (int i = 0; i < contacts.size(); i++) {
            System.out.println((i + 1) + ". " + contacts.get(i));
        }
        System.out.println();
    }

    private static void editContact(Scanner scanner) {
        viewAllContacts();

        if (contacts.isEmpty()) {
            System.out.println("No contacts available for editing.");
            return;
        }
        
        System.out.print("Select a contact to edit (enter index): ");
        int index = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        if (index < 1 || index > contacts.size()) {
            System.out.println("Invalid index. Please try again.");
            return;
        }

        Contact contactToEdit = contacts.get(index - 1);
        System.out.println("Editing contact:");
        System.out.println(contactToEdit);

        System.out.print("Enter updated details:\nEnter name: ");
        String updatedName = scanner.nextLine();

        System.out.print("Enter phone number: ");
        String updatedPhoneNumber = scanner.nextLine();

        System.out.print("Enter email: ");
        String updatedEmail = scanner.nextLine();

        Contact updatedContact = new Contact(updatedName, updatedPhoneNumber, updatedEmail);
        contacts.set(index - 1, updatedContact);
        System.out.println("Contact updated successfully!");
        System.out.println();
    }

    private static void deleteContact(Scanner scanner) {
        viewAllContacts();

        if (contacts.isEmpty()) {
            System.out.println("No contacts available for deletion.");
            return;
        }

        System.out.print("Select a contact to delete (enter index): ");
        int index = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        if (index < 1 || index > contacts.size()) {
            System.out.println("Invalid index. Please try again.");
            return;
        }

        Contact contactToDelete = contacts.remove(index - 1);
        System.out.println("Contact deleted successfully:");
        System.out.println(contactToDelete);
        System.out.println();
    }

    private static void loadContacts() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(SAVE_FILE))) {
            contacts = (List<Contact>) ois.readObject();
            System.out.println("Loading contacts... Contacts loaded");
        } catch (FileNotFoundException e) {
            System.out.println("No previous save file found. Starting with an empty address book.");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println();
    }
    
    private static void saveContacts() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(SAVE_FILE))) {
            oos.writeObject(contacts);
            System.out.println("Contacts saved");
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println();
    }
}
