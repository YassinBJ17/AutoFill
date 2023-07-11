package SDDD.file;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;

import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFTable;
import org.apache.poi.xwpf.usermodel.XWPFTableCell;
import org.apache.poi.xwpf.usermodel.XWPFTableRow;

import static COMMUN.GraphicUserInterfaces.Error_interface;
import static SDDD.file.ExtractTextFromSDDD.removeInvisibleChars;
import static SUTC.file.SutcCreationProccess.switchArray;
import static COMMUN.LoggerInitialize.*;

public class ExtractCausesEffectTable {

    public static final String WHITE_COLOR_HEXA="FFFFFF";
    private static int rowNumber=-1;

    private static XWPFDocument document;

    public static boolean IsRequirement(String requirement) {
        String[] notReq={"DO NOTHING","EFFECTS","ALL OTHER CASE","CAUSES","NO EFFECT","ALWAYS","NO EFFECTS","ALL THE OTHER CASES","NO DATA TO READ"};
        requirement=requirement.replaceAll("[^a-zA-Z]", " ");
        requirement=requirement.trim();
        if( Objects.equals(requirement, ""))
        {
            return false;
        }
        for (String req:notReq)
        {
            if (requirement.equalsIgnoreCase(req)) {
                return false;
            }
        }
        return true;
    }

    public static void AddCause(String cell,ArrayList<String> cause) {

        String causes = cell.trim();
        //logDebug(causes);

        if ((!(causes.startsWith("["))) && (!(causes.endsWith("]")))) {
            if ((causes.toUpperCase().contains("OR")) || (causes.toUpperCase().contains("AND"))) {

                String[] cause_table = causes.split("\\s+(?i)(or|and)\\s+");
                cause.addAll(Arrays.asList(cause_table));
            } else
                cause.add(causes);
        } else {
            causes = causes.replaceAll("\\(", "");
            causes = causes.replaceAll("\\)", "");

            while (!Objects.equals(causes.trim(), "")) {
                String c = causes.substring(causes.indexOf("["), causes.indexOf("]") + 1);
                c = removeInvisibleChars(c);
                cause.add(c);
                causes = causes.trim().substring(causes.indexOf("]") + 1);
                if (!causes.trim().equals("")) {
                    try {


                        causes = causes.trim().substring(causes.indexOf("[") - 1);
                    } catch (Exception e) {
                        // If there is an error reading the file, print the stack trace and return null.
                        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                        log4Error(methodName + " : " + e.getMessage());
                    }
                }
            }
        }
    }

    public static void ExtractCausesEffects(XWPFTableRow row,ArrayList<String> cause, ArrayList<String> effect) {

        XWPFTableCell cell;
        int number_Of_Cause=0;
        int start_Of_Cause=0;

        for (int i = 0; i < row.getTableCells().size(); i++) {
            cell = row.getCell(i);

            if (((Objects.equals(cell.getColor(), WHITE_COLOR_HEXA)) || Objects.equals(cell.getColor(), "auto") || Objects.equals(cell.getColor(), null)) && (IsRequirement(cell.getText())))
                effect.add(cell.getText().trim());

            else
            {

                if(IsRequirement(cell.getText())) {

                    if (start_Of_Cause==0)
                    {
                        start_Of_Cause=i;
                    }

                    number_Of_Cause++;
                }if(number_Of_Cause==1)
                    rowNumber++; // stored the row
            }
        }

        if(number_Of_Cause>=2) { // if the line in cause/effect table is >3


            if (!switchArray[rowNumber]) { // if 'if'
                for (int i = start_Of_Cause; i <= start_Of_Cause+number_Of_Cause-1; i +=2) {
                    cell = row.getCell(i);
                    log4Debug(cell.getText());
                    if (IsRequirement(cell.getText()))
                        AddCause(cell.getText(), cause);
                }
            } else {

                for (int i = start_Of_Cause; i < start_Of_Cause+number_Of_Cause-1; i++) { // if 'switch'

                    cell = row.getCell(i);

                    log4Debug(cell.getText());
                    if (IsRequirement(cell.getText()))
                        AddCause(cell.getText(), cause);
                }
            }
        }else {
            for (int i = start_Of_Cause; i <= start_Of_Cause+number_Of_Cause-1; i +=2) {
                cell = row.getCell(i);
                if (IsRequirement(cell.getText()))
                    AddCause(cell.getText(), cause);
            }
        }


    }

    private static void openWordFile(String path){
        try {

            // Open the docx file
            File file = new File(path);
            FileInputStream fis = new FileInputStream(file);
            document = new XWPFDocument(fis);

            }  catch (Exception e){
                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                log4Error(methodName+" : "+e.getMessage() );
                Error_interface(String.valueOf(e));
            }

    }

    private static void closeWordFile(){


        try {
            document.close();
        }   catch (Exception e){
        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
        log4Error(methodName+" : "+e.getMessage() );
        Error_interface(String.valueOf(e));
    }

    }
    public static void Extract_Table(String path, ArrayList<String> cause, ArrayList<String> effect,int CauseEffectTableOrder) {

        rowNumber=-1;
        // Open the document
        openWordFile(path);

        // Get the first table in the document
        XWPFTable table = document.getTables().get(CauseEffectTableOrder);
        // Loop through each row of the table
      //  log4Info("Extract Cause/Effect Table progress");
        for (int i = 0; i < table.getRows().size(); i++) {

            ExtractCausesEffects( table.getRow(i),cause,effect);

        }
        // Close the document
        closeWordFile();

    }
}

