package Basics;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;

class Contact {
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

    public void setName(String name) {
        this.name = name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Contact{" +
                "name='" + name + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}

class AddressBook {
    private Map<String, Contact> hashMapContacts;
    private Map<String, Contact> treeMapContacts;

    public AddressBook() {
        hashMapContacts = new HashMap<>();
        treeMapContacts = new TreeMap<>();
    }

    public void addContactHashMap(Contact contact) {
        hashMapContacts.put(contact.getName(), contact);
    }

    public void addContactTreeMap(Contact contact) {
        treeMapContacts.put(contact.getName(), contact);
    }

    public Contact searchContactHashMap(String name) {
        return hashMapContacts.get(name);
    }

    public Contact searchContactTreeMap(String name) {
        return treeMapContacts.get(name);
    }

    public void updateContactHashMap(String oldName, Contact newContact) {
        hashMapContacts.remove(oldName);
        hashMapContacts.put(newContact.getName(), newContact);
    }

    public void updateContactTreeMap(String oldName, Contact newContact) {
        treeMapContacts.remove(oldName);
        treeMapContacts.put(newContact.getName(), newContact);
    }

    public void deleteContactHashMap(String name) {
        hashMapContacts.remove(name);
    }

    public void deleteContactTreeMap(String name) {
        treeMapContacts.remove(name);
    }

    public long measureAddEfficiencyHashMap(java.util.List<Contact> contacts) {
        long startTime = System.currentTimeMillis();
        for (Contact contact : contacts) {
            addContactHashMap(contact);
        }
        long endTime = System.currentTimeMillis();
        return endTime - startTime;
    }

    public long measureAddEfficiencyTreeMap(java.util.List<Contact> contacts) {
        long startTime = System.currentTimeMillis();
        for (Contact contact : contacts) {
            addContactTreeMap(contact);
        }
        long endTime = System.currentTimeMillis();
        return endTime - startTime;
    }

    public long measureSearchEfficiencyHashMap(java.util.List<String> names) {
        long startTime = System.currentTimeMillis();
        for (String name : names) {
            searchContactHashMap(name);
        }
        long endTime = System.currentTimeMillis();
        return endTime - startTime;
    }

    public long measureSearchEfficiencyTreeMap(java.util.List<String> names) {
        long startTime = System.currentTimeMillis();
        for (String name : names) {
            searchContactTreeMap(name);
        }
        long endTime = System.currentTimeMillis();
        return endTime - startTime;
    }
}

public class main {
    private AddressBook addressBook;
    private JFrame frame;
    private JTextField nameField, phoneField, emailField;
    private JTextArea outputArea;

    public main() {
        addressBook = new AddressBook();
        initializeUI();
    }

    private void initializeUI() {
        frame = new JFrame("Address Book");
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel inputPanel = new JPanel(new GridLayout(4, 2));
        inputPanel.add(new JLabel("Name:"));
        nameField = new JTextField();
        inputPanel.add(nameField);
        inputPanel.add(new JLabel("Phone:"));
        phoneField = new JTextField();
        inputPanel.add(phoneField);
        inputPanel.add(new JLabel("Email:"));
        emailField = new JTextField();
        inputPanel.add(emailField);

        JButton addButton = new JButton("Add");
        addButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                String phone = phoneField.getText();
                String email = emailField.getText();
                Contact contact = new Contact(name, phone, email);
                addressBook.addContactHashMap(contact);
                addressBook.addContactTreeMap(contact);
                outputArea.append("Contact added: " + contact + "\n");
            }
        });

        JButton searchButton = new JButton("Search");
        searchButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                Contact contactHashMap = addressBook.searchContactHashMap(name);
                if (contactHashMap != null) {
                    outputArea.append("Contact found in HashMap: " + contactHashMap + "\n");
                } else {
                    outputArea.append("Contact not found in HashMap\n");
                }

                Contact contactTreeMap = addressBook.searchContactTreeMap(name);
                if (contactTreeMap != null) {
                    outputArea.append("Contact found in TreeMap: " + contactTreeMap + "\n");
                } else {
                    outputArea.append("Contact not found in TreeMap\n");
                }
            }
        });

        JButton deleteButton = new JButton("Delete");
        deleteButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                addressBook.deleteContactHashMap(name);
                addressBook.deleteContactTreeMap(name);
                outputArea.append("Contact deleted: " + name + "\n");
            }
        });

        JButton clearButton = new JButton("Clear");
        clearButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                nameField.setText("");
                phoneField.setText("");
                emailField.setText("");
                outputArea.setText("");
            }
        });

        JButton compareButton = new JButton("Compare Efficiency");
        compareButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                java.util.List<Contact> contacts = generateContacts(10000);
                java.util.List<String> names = generateNames(10000);

                long addTimeHashMap = addressBook.measureAddEfficiencyHashMap(contacts);
                long addTimeTreeMap = addressBook.measureAddEfficiencyTreeMap(contacts);

                long searchTimeHashMap = addressBook.measureSearchEfficiencyHashMap(names);
                long searchTimeTreeMap = addressBook.measureSearchEfficiencyTreeMap(names);

                outputArea.append("Add Efficiency (HashMap): " + addTimeHashMap + " milliseconds\n");
                outputArea.append("Add Efficiency (TreeMap): " + addTimeTreeMap + " milliseconds\n");

                outputArea.append("Search Efficiency (HashMap): " + searchTimeHashMap + " milliseconds\n");
                outputArea.append("Search Efficiency (TreeMap): " + searchTimeTreeMap + " milliseconds\n");
            }
        });

        outputArea = new JTextArea();
        outputArea.setEditable(false);

        JPanel buttonPanel = new JPanel(new GridLayout(1, 5));
        buttonPanel.add(addButton);
        buttonPanel.add(searchButton);
        buttonPanel.add(deleteButton);
        buttonPanel.add(clearButton);
        buttonPanel.add(compareButton);

        frame.getContentPane().setLayout(new BorderLayout());
        frame.getContentPane().add(inputPanel, BorderLayout.NORTH);
        frame.getContentPane().add(new JScrollPane(outputArea), BorderLayout.CENTER);
        frame.getContentPane().add(buttonPanel, BorderLayout.SOUTH);

        frame.setVisible(true);
    }

    private java.util.List<Contact> generateContacts(int numContacts) {
        java.util.List<Contact> contacts = new ArrayList<>();
        for (int i = 0; i < numContacts; i++) {
            contacts.add(new Contact("Name " + i, "1234567890", "name" + i + "@example.com"));
        }
        return contacts;
    }

    private java.util.List<String> generateNames(int numNames) {
        java.util.List<String> names = new ArrayList<>();
        for (int i = 0; i < numNames; i++) {
            names.add("Name " + i);
        }
        return names;
    }

    public static void main(String[] args) {
        new main();
    }
}
