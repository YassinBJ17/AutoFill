package docx.file;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;
import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFTable;
import org.apache.poi.xwpf.usermodel.XWPFTableCell;
import org.apache.poi.xwpf.usermodel.XWPFTableRow;
import static docx.file.ExtractText.removeInvisibleChars;

public class ExtractTable {

    public static final String WHITE_COLOR_HEXA="FFFFFF";


    public static boolean IsNotReq(String requirement)
    {
        String[] notReq={"DO NOTHING","EFFECTS","ALL OTHER CASES","ALL OTHER CASE","CAUSES","EXIT FUNCTION","NO EFFECT","EXIT THE FUNCTION","ALWAYS","NO EFFECTS","ALL THE OTHER CASES","NO DATA TO READ"};
        requirement=requirement.toUpperCase();
        requirement=requirement.replaceAll("[^a-zA-Z]", " ");
        requirement=requirement.trim();
        if( Objects.equals(requirement, ""))
        {
            return false;
        }
        for (String req:notReq)
        {
            if (requirement.equals(req)) {
                return false;
            }
        }
        return true;
    }
    public static void Extract_Table(String path, ArrayList<String> cause, ArrayList<String> effect) throws IOException {

            // Open the docx file
            File file = new File(path);
            FileInputStream fis = new FileInputStream(file);
            XWPFDocument document = new XWPFDocument(fis);

            // Get the first table in the document
            XWPFTable table = document.getTables().get(0);
            // Loop through each row of the table
            for (XWPFTableRow row : table.getRows()) {
                // Loop through each cell of the row
                for (XWPFTableCell cell : row.getTableCells())
                { // Check if the cell has a white background
                    if((Objects.equals(cell.getColor(), WHITE_COLOR_HEXA))||Objects.equals(cell.getColor(), "auto")||Objects.equals(cell.getColor(), null)){

                        if (IsNotReq(cell.getText()))
                        {
                            effect.add(removeInvisibleChars(cell.getText().trim()));


                        }
                    }
                    else
                    {
                        if (IsNotReq(cell.getText()))
                        {
                            String causes=removeInvisibleChars(cell.getText()).trim();
                            if ((!(causes.startsWith("[")))&&(!(causes.endsWith("]"))))
                                cause.add(causes);
                            else
                            {
                                causes=causes.replaceAll("\\(","");
                                causes=causes.replaceAll("\\)","");

                                while(!Objects.equals(causes.trim(), ""))
                                {
                                    String c=causes.substring(causes.indexOf("["),causes.indexOf("]")+1);
                                    c=c.replaceAll("[^\\w\\[\\]]", " ").trim();
                                    cause.add(c);
                                    causes=causes.trim().substring(causes.indexOf("]")+1);

                                    if (!causes.trim().equals(""))
                                    {
                                        causes=causes.trim().substring(causes.indexOf("[")-1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            // Close the document
        document.close();
        }
    }

