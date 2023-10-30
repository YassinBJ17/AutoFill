package file.sutc.B1_Sheet.Commun;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;

import static file.sutc.SutcCreationProcess.workbook;

public class RemoveExtraColumn {


    public static void removeExtraCols(int sheetIndex, int columnIndex) {

        Sheet sheet = workbook.getSheetAt(sheetIndex);

        for (Row row : sheet) {
            Cell cellToDelete = row.getCell(columnIndex);
            if (cellToDelete != null) {
                row.removeCell(cellToDelete);
            }

            // Shift cells to the left to fill the gap
            for (int i = columnIndex + 1; i <= row.getLastCellNum(); i++) {
                Cell currentCell = row.getCell(i);
                if (currentCell != null) {
                    Cell newCell = row.createCell(i - 1, currentCell.getCellType());
                    newCell.setCellStyle(currentCell.getCellStyle());

                    switch (currentCell.getCellType()) {
                        case BLANK:
                            break;
                        case BOOLEAN:
                            newCell.setCellValue(currentCell.getBooleanCellValue());
                            break;
                        case NUMERIC:
                            newCell.setCellValue(currentCell.getNumericCellValue());
                            break;
                        case STRING:
                            newCell.setCellValue(currentCell.getStringCellValue());
                            break;
                        case FORMULA:
                            newCell.setCellFormula(currentCell.getCellFormula());
                            break;
                        default:
                            break;
                    }

                    row.removeCell(currentCell);
                }
            }
        }
    }
}



