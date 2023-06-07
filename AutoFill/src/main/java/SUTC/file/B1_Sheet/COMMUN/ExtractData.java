package SUTC.file.B1_Sheet.COMMUN;

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

        invalid="[0x80000000.."+min+"-1] U ["+max+" +1..0x7FFFFFFF]";
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
                {"boolean_t", "{FALSE,TRUE}","[0x2..0xFFFFFFFF]"},
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
    public static String Access_Detect(String[] LLR, String p) {
        String r="";
        int pos=0;

        for (int i = 0; i <LLR.length ; i++) {
            if(LLR[i].toUpperCase().contains("PARAMETERS"))
            {
                pos=i;
                break;
            }}

        for (int i = pos; i <LLR.length ; i++) {

            if(LLR[i].contains(p)){
                r= (LLR[i].substring(LLR[i].indexOf("(")+1,LLR[i].indexOf(")")));

                if ((!r.equals("R"))&&(!r.equals("W"))&&(!r.equals("R/W")))
                {
                    r=LLR[i].substring(LLR[i].indexOf(")")+1);
                    r= r.substring(r.indexOf("(")+1,r.indexOf(")"));
                }

                return r;
            }
        }
        return r;
    }


}
