package file.sutc.Commun;

import java.util.ArrayList;
import java.util.List;


    public class LongTextDivider{
        public static List<String> divideLongText(String longText, int maxLength) {
            List<String> result = new ArrayList<>();
            int start = 0;
            int end = maxLength;
            while (start < longText.length()) {
                if (end < longText.length() && !Character.isWhitespace(longText.charAt(end)) &&
                        !Character.isWhitespace(longText.charAt(end - 1))) {
                    while (end > start && !Character.isWhitespace(longText.charAt(end - 1))) {
                        end--;
                    }
                }
                result.add(longText.substring(start, end));
                start = end;
                end = Math.min(start + maxLength, longText.length());
            }
            return result;
        }
    }

