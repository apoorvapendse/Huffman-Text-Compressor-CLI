import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("File Input Swing App");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400); // Increased the height to accommodate text area

        JPanel panel = new JPanel(new BorderLayout());

        JButton openButton = new JButton("Open File");
        JTextField filePathTextField = new JTextField(20);

        JTextArea fileContentTextArea = new JTextArea(10, 30);
        fileContentTextArea.setWrapStyleWord(true);
        fileContentTextArea.setLineWrap(true);
        JScrollPane scrollPane = new JScrollPane(fileContentTextArea);

        openButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                int result = fileChooser.showOpenDialog(frame);

                if (result == JFileChooser.APPROVE_OPTION) {
                    File selectedFile = fileChooser.getSelectedFile();
                    String filePath = selectedFile.getAbsolutePath();
                    filePathTextField.setText(filePath);

                    // Read the selected text file
                    try {
                        BufferedReader reader = new BufferedReader(new FileReader(selectedFile));
                        String line;
                        StringBuilder fileContent = new StringBuilder();
                        while ((line = reader.readLine()) != null) {
                            fileContent.append(line).append("\n");
                        }
                        reader.close();
                        fileContentTextArea.setText(fileContent.toString());
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(frame, "Error reading the file: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        });

        panel.add(openButton, BorderLayout.NORTH);
        panel.add(filePathTextField, BorderLayout.CENTER);
        frame.add(panel, BorderLayout.NORTH);
        frame.add(scrollPane, BorderLayout.CENTER);

        frame.setVisible(true);
    }
}
