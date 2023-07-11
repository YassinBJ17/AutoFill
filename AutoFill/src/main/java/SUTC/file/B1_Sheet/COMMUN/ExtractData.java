package SUTC.file.B1_Sheet.COMMUN;

import static COMMUN.GraphicUserInterfaces.Error_interface;
import static COMMUN.LoggerInitialize.log4Error;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.Parameters;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.INDEX_OF_NAME;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.INDEX_OF_TYPE;
import static SUTC.file.SutcCreationProccess.lowLevelReq;

public class ExtractData {

    public static String Extract_Invalid_Domain(String domain){

        if (domain.equals("-")||domain.equals("not exist in the DD"))
            return "-";

        String max,min,invalid;
        domain=domain.substring(domain.indexOf("{")+1);
        domain=domain.trim();
        min=domain.substring(0,domain.indexOf(" "));

        max=domain.substring(domain.lastIndexOf(",")+1);
        max=max.trim();
        max=max.replace("}"," ");
        max=max.substring(0,max.indexOf(" "));

        //invalid="[0x80000000.."+min+"-1] U ["+max+" +1..0x7FFFFFFF]";
        invalid="[0x80000000.."+min+"[ # ]"+max+"..0x7FFFFFFF]";
        return invalid;
    }
    public static String[] Extract_Domain(String type) {
        String [] tab = new String[3];
        tab[0]="";
        String[][] domain = {
                {"uint8_t", "[0..0xFF]","-"},
                {"uint16_t", "[0..0xFFFF]","-"},
                {"uint32_t", "[0..0xFFFFFFFF]","-"},
                {"uint64_t", "[0..0xFFFFFFFFFFFFFFFF]","-"},
                {"boolean_t", "{FALSE,TRUE}","[0x70000000..FALSE[ # ]TRUE..0x8FFFFFFF]"},
                {"float32_t", "[-3.4E38..3.4E38]","-"},
                {"float64_t", "[2.2E-308..1.7E308]","-"}
        };

        tab[0]="-";
        tab[1]="-";

        for (int i = 0; i <= 6; i++) {

            if(domain[i][0].contains(type.trim())){
                tab[0]=domain[i][1];
                tab[1]=domain[i][2];
                return tab;
            }
        }
        return tab;
    }
    public static String Access_Detect( int p) {
        String r="";
        int pos_start=0,pos_end=0;

        for (int i = 0; i <lowLevelReq.length ; i++) {
            if(lowLevelReq[i].toUpperCase().contains("PARAMETERS"))
            {
                pos_start=i;
                break;
            }
        }
        for (int i = 0; i <lowLevelReq.length ; i++) {
            if(lowLevelReq[i].toUpperCase().contains("[COV.REQ"))
            {
                pos_end=i;
                break;
            }
        }



        for (int i = pos_start; i <pos_end ; i++) {


            if(lowLevelReq[i].contains( Parameters[p][INDEX_OF_NAME])||lowLevelReq[i].contains( Parameters[p][INDEX_OF_TYPE])){

                r= (lowLevelReq[i].substring(lowLevelReq[i].indexOf("(")+1,lowLevelReq[i].indexOf(")")));

                if ((!r.equals("R"))&&(!r.equals("W"))&&(!r.equals("R/W"))&&(!r.equals("R\\W")))
                {
                    try {
                        r=lowLevelReq[i].substring(lowLevelReq[i].indexOf(")")+1);
                        r= r.substring(r.indexOf("(")+1,r.indexOf(")"));
                    } catch (IndexOutOfBoundsException e) {
                        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                        log4Error(methodName+" : "+e.getMessage() );
                        Error_interface(String.valueOf(e));
                    }
                }

                return r;
            }
        }
        return r;
    }


}
