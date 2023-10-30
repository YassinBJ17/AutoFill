package file.s3d;

import org.apache.poi.xwpf.extractor.XWPFWordExtractor;
import org.apache.poi.xwpf.usermodel.*;

import java.io.FileInputStream;
import java.io.IOException;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.commun.LoggerInitialize.*;

public class ExtractText {

   // public static final String PUNCTUATION_MARKS = "[^A-Za-z0-9 :\\r.\\n_\\-+<>\\/{}\\[\\]()\\*]";


    public static String removeInvisibleChars(String input) {
        // Define a regular expression that matches invisible characters
        // String pattern1= "[^a-zA-Z0-9!\"#$%&'()*+,\\-./;<=>?@[\\[\\\\]^_`{|}~\\s\\n]]";

         String pattern = "[^a-zA-Z0-9!\\[\\]\\s\\n \\-#$%&\"'‘’:()*+,./;<=>?@^_`{|}~]" ;
         input=input.replaceAll("\t"," ");
        return input.replaceAll(pattern, "");

       // return input.replaceAll(pattern1, "");

    }


    public static String ExtractTextFromSDDD(String path) {
        String text = null;
        try {
            FileInputStream fis = new FileInputStream(path);
            XWPFDocument doc = new XWPFDocument(fis);
            XWPFWordExtractor extractor = new XWPFWordExtractor(doc);
            text = extractor.getText();
            fis.close();
        } catch (IOException e) {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
log4Error(methodName+" : "+e.getMessage() );
            Error_interface(String.valueOf(e));
        }
        assert text != null;


        return removeInvisibleChars(text);
    }

















}