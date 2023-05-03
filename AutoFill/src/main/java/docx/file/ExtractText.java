package docx.file;

import org.apache.poi.xwpf.extractor.XWPFWordExtractor;
import org.apache.poi.xwpf.usermodel.*;

import javax.swing.*;
import java.io.FileInputStream;
import java.io.IOException;

public class ExtractText {

    public static final String PUNCTUATION_MARKS="[^A-Za-z0-9 :\\r\\.\\n_\\-\\+\\ \\<\\> \\/ \\{\\}\\[\\(\\)\\]\\*]+";

    public static String removeInvisibleChars(String input) {
        // Define a regular expression that matches invisible characters
        return input.replaceAll(PUNCTUATION_MARKS, "");


    }


    public static String id;

    public static String Extract_Text(String path) {
        String text = null;
        try {
            FileInputStream fis = new FileInputStream(path);
            XWPFDocument doc = new XWPFDocument(fis);
            XWPFWordExtractor extractor = new XWPFWordExtractor(doc);
            text = extractor.getText();
            fis.close();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Error: " + e.getMessage());

        }

        return removeInvisibleChars(text);
    }

















}