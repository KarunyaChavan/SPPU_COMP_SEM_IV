import java.io.*;

class Student{
    int rollNumber;
    String name;
    String div;
    String address;

    public Student(int r, String n,String c, String a){
        rollNumber = r;
        name = n;
        div = c;
        address = a;
    }

    public String record(){
         return ("Roll Number: " + rollNumber + "\nName: " + name + "\nDivision: " + div + "\nAddress: " + address);
    }
}

public class StudentDatabase{
    private static final String fileName = "studentInfo.txt";
    public static void main(String[] args) {
        try{
            BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
            while(true){
                System.out.println("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ MENU _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n1. Add Student\n2. Delete Student\n3. Display Student Information\n4. Exit.");
                System.out.print("\nEnter Your Choice = ");
                int opt = Integer.parseInt(buff.readLine());
                switch(opt){
                    case 1:
                        addStudent(buff);
                        break;
                    case 2:
                        deleteStudent(buff);
                        break;
                    case 3:
                        displayStudent(buff);
                        break;
                    case 4:
                        System.out.println("Exiting program.");
                        return;
                    default:
                        System.out.println("Invalid choice. Please enter a number between 1 and 4.");
                }
            }
        }
        catch (IOException | NumberFormatException e) {
            e.printStackTrace();
        }
    }


    private static void addStudent(BufferedReader buff) throws IOException{
        System.out.print("Enter Roll Number: ");
            int rollNumber = Integer.parseInt(buff.readLine());
            System.out.print("Enter Name: ");
            String name = buff.readLine();
            System.out.print("Enter Division: ");
            String division = buff.readLine();
            System.out.print("Enter Address: ");
            String address = buff.readLine();

            Student s = new Student(rollNumber, name, division, address);

            try(FileOutputStream fout = new FileOutputStream(fileName)){
                fout.write(s.record().getBytes());
                fout.write("\n".getBytes());
                System.out.println("Student Data Added Successfully");
            }
            catch(IOException e){
                e.printStackTrace();
            }
    }

    private static void deleteStudent(BufferedReader reader) throws IOException {
        System.out.print("Enter Roll Number of student to delete: ");
        int rollNumberToDelete = Integer.parseInt(reader.readLine());

        try (FileInputStream fis = new FileInputStream(fileName);
             BufferedReader fileReader = new BufferedReader(new InputStreamReader(fis));
             FileOutputStream fos = new FileOutputStream(fileName + ".tmp")) {

            String line;
            while ((line = fileReader.readLine()) != null) {
                String[] parts = line.split("\n");
                String[] studentInfo = parts[0].split(": ");
                int rollNumber = Integer.parseInt(studentInfo[1]);

                if (rollNumber != rollNumberToDelete) {
                    fos.write((line + "\n").getBytes());
                }
            }
        }

        File file = new File(fileName);
        File tempFile = new File(fileName + ".tmp");
        file.delete();
        tempFile.renameTo(file);

        System.out.println("Student with Roll Number " + rollNumberToDelete + " deleted successfully.");
    }

    private static void displayStudent(BufferedReader reader) throws IOException {
        System.out.print("Enter Roll Number of student to display: ");
        int rollNumberToDisplay = Integer.parseInt(reader.readLine());
        boolean found = false;

        try (FileInputStream fis = new FileInputStream(fileName);
             BufferedReader fileReader = new BufferedReader(new InputStreamReader(fis))) {

            String line;
            while ((line = fileReader.readLine()) != null) {
                // String[] parts = line.split("\n");
                // String[] studentInfo = parts[0].split(": ");
                // int rollNumber = Integer.parseInt(studentInfo[1]);

                // if (rollNumber == rollNumberToDisplay) {
                //     System.out.println("\nStudent Information:\n" + line);
                //     found = true;
                //     break;
                // }
                System.out.println(line);
            }
        }
        if (!found) {
            System.out.println("Student with Roll Number " + rollNumberToDisplay + " not found.");
        }
    }
}