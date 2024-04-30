package file.s3d;

import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;

import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFTable;
import org.apache.poi.xwpf.usermodel.XWPFTableCell;
import org.apache.poi.xwpf.usermodel.XWPFTableRow;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.s3d.ExtractTextFromS3D.removeInvisibleChars;
import static file.commun.LoggerInitialize.*;
import static file.sutc.Commun.switchOrIfCalled.CheckIfSwitchExistInCode;
import static file.sutc.Commun.switchOrIfCalled.switchArray;
import static file.sutc.SutcCreationProcess.causesTable;
import static file.sutc.SutcCreationProcess.effectsTable;

public class ExtractCausesEffectTable {

    public static final String WHITE_COLOR_HEXA="FFFFFF";
    private static int rowNumber=-1;
    public static int causeEffectTableOrder;
    private static XWPFDocument document;


    public static int getTheFirstCauseEffectTable(String document_path){

        XWPFTableCell cell;
        XWPFTable table;
        try {
            File file = new File(document_path);
            FileInputStream fis = new FileInputStream(file);
            XWPFDocument document = new XWPFDocument(fis);

            for (int i = 0; i < document.getTables().size(); i++) {
                table = document.getTables().get(i);
                cell = table.getRow(0).getCell(1);
                if (cell!=null)
                    if(cell.getText().toLowerCase().contains("causes")){
                        document.close();
                        return i;
                    }
            }
            document.close();
        } catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
            Error_interface(String.valueOf(e));
        }
        return -1 ;
    }

    public static boolean IsRequirement(String requirement) {

        String[] notReq={"DO NOTHING","EFFECTS","EFFECT","ALL OTHER CASES","ALL OTHER CASE","CAUSES","CAUSE","NO EFFECT","ALWAYS","NO EFFECTS","ALL THE OTHER CASES","NO DATA TO READ"};

        requirement=requirement.replaceAll("[^a-zA-Z]", " ");
        requirement=requirement.trim();

        if( requirement.isEmpty())
            return false;

        for (String req:notReq)
            if (requirement.equalsIgnoreCase(req))
                return false;


        return true;
    }

    public static void AddCause(String cell,ArrayList<String> cause) {

        String causes = cell.trim();
        //logDebug(causes);
        try {
        if ((!(causes.startsWith("["))) && (!(causes.endsWith("]")))) {
            if ((causes.contains("OR")) || (causes.contains("AND"))) { // OR , AND are required uppercase

                String[] cause_table = causes.split("(?<!\\bBITWISE)\\s+(OR|AND)\\s+");
                cause.addAll(Arrays.asList(cause_table));
            } else
                cause.add(causes);
        } else {
            causes = causes.replaceAll("\\(", "");
            causes = causes.replaceAll("\\)", "");
            causes =causes.replaceAll(":","");

            while (!Objects.equals(causes.trim(), "")) {

                String c = causes.substring(causes.indexOf("["), causes.indexOf("]") + 1);
                c = removeInvisibleChars(c);
                cause.add(c);
                causes = causes.trim().substring(causes.indexOf("]") + 1);
                if (!causes.trim().equals("")) {

                    causes = causes.trim().substring(causes.indexOf("[") - 1);
                }
            }
        }
        }catch (Exception ignored){

        }
    }

    public static void ExtractCausesEffects(XWPFTableRow row) {

        XWPFTableCell cell;
        int number_Of_Cause=0;
        int start_Of_Cause=0;

        for (int i = 0; i < row.getTableCells().size(); i++) {
            cell = row.getCell(i);

            if (((Objects.equals(cell.getColor(), WHITE_COLOR_HEXA)) || Objects.equals(cell.getColor(), "auto") ||
                    Objects.equals(cell.getColor(), null)) && (IsRequirement(cell.getText()))) {

                effectsTable.add(cell.getText());

            }
            else
            {
                if(IsRequirement(cell.getText())) {
                    cell = row.getCell(i);
                    AddCause(cell.getText(), causesTable);
                }
/*
                    if (start_Of_Cause==0)
                        start_Of_Cause=i;

                    number_Of_Cause++;
                }
                if(number_Of_Cause==1)
                    rowNumber++; // stored the row
            */}
        }

 /*       if(number_Of_Cause>=2) { // if the line in cause/effect table is >3

            if (!switchArray[rowNumber]) { // if 'if'
                for (int i = start_Of_Cause; i <= start_Of_Cause+number_Of_Cause; i +=2) {
                    cell = row.getCell(i);
                    log4Debug(cell.getText());
                    if (IsRequirement(cell.getText()))
                        AddCause(cell.getText(), causesTable);
                }
            } else {

                for (int i = start_Of_Cause; i < start_Of_Cause+number_Of_Cause; i++) { // if 'switch'

                    cell = row.getCell(i);
                    if (IsRequirement(cell.getText()))
                        log4Debug(cell.getText());
                        AddCause(cell.getText(), causesTable);
                }
            }
        }else {
            for (int i = start_Of_Cause; i <= start_Of_Cause+number_Of_Cause-1; i +=2) {
                cell = row.getCell(i);
                if (IsRequirement(cell.getText())){
                    AddCause(cell.getText(), causesTable);
            }
            }
        }*/
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
    public static void Extract_Table(String path) {


        CheckIfSwitchExistInCode(); // check if the code contains switch statements
        rowNumber=-1;
        // Open the document
        openWordFile(path);


        XWPFTable table = document.getTables().get(causeEffectTableOrder);

        //  log4Info("Extract Cause/Effect Table progress");
        for (int i = 0; i < table.getRows().size(); i++)
            ExtractCausesEffects( table.getRow(i));


        closeWordFile();
        causeEffectTableOrder++;

    }
}

