package SUTC.file.Commun;

import static SUTC.file.Commun.ExcelManipulation.Fill_Cell;
import static SUTC.file.Commun.ExcelRowsAndColsConstants.*;
import static SUTC.file.Commun.utcUftNumberCounter.numberOfCauses;
import static SUTC.file.SutcCreationProcess.*;

public class LlrTraceability {

    public static void llrTraceabilityFilling(){

        String llr_traceability;
        for (int i = 0; i < llrOfTheFunction.length ; i++) {

            if (llrOfTheFunction[i].toUpperCase().contains("REQUIREMENTS")){
                llr_traceability= llrOfTheFunction[i+1];
                llr_traceability=llr_traceability.substring(0,llr_traceability.length()-3);
                Fill_Cell(llr_traceability, SHEET_B0_INDEX, CELL_ROW_3, CELL_COL_3+ numberOfUFT);
                Fill_Cell(llr_traceability, SHEET_B0_INDEX, CELL_ROW_3+Math.max(2, numberOfCauses), CELL_COL_3+ numberOfUFT);

                    for (int j = 10; j < CELL_COL_10+numberOfUTC ; j++) {
                    Fill_Cell(llr_traceability, SHEET_B1_INDEX, CELL_ROW_6, j);
                }
                break;
            }

        }

    }
}
