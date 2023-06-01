package docx.file;

import org.apache.poi.xwpf.extractor.XWPFWordExtractor;
import org.apache.poi.xwpf.usermodel.*;

import javax.swing.*;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static services.GUInterfaces.Error_interface;
import static services.Logger_init.logger4j;

public class ExtractText {

   // public static final String PUNCTUATION_MARKS = "[^A-Za-z0-9 :\\r.\\n_\\-+<>\\/{}\\[\\]()\\*]";


    public static String removeInvisibleChars(String input) {
        // Define a regular expression that matches invisible characters

        String pattern = "[^a-zA-Z0-9!\"#$%&'()*+,-./:;<=>?@[\\[\\\\]^_`{|}~\\s\\r.\\n]¶]";
        return input.replaceAll(pattern, "");

    }


    public static String Extract_Text(String path) {
        String text = null;
        try {
            FileInputStream fis = new FileInputStream(path);
            XWPFDocument doc = new XWPFDocument(fis);
            XWPFWordExtractor extractor = new XWPFWordExtractor(doc);
            text = extractor.getText();
            fis.close();
        } catch (IOException e) {
            logger4j.error(e);
            Error_interface(String.valueOf(e));
            //JOptionPane.showMessageDialog(null, "Error: " + e.getMessage());

        }
        assert text != null;
        return removeInvisibleChars(text);
    }

















}