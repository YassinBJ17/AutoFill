package file.sutc.Commun;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


    public class LongTextDivider{


        public static final int MAX_LINE_PER_EFFECT_CELL=31;

        public static List<String> divideLongText(String text) {
            String[] lines = text.split("\n");

            int numOfChunks = (int) Math.ceil((double) lines.length / MAX_LINE_PER_EFFECT_CELL);
            String[] chunks = new String[numOfChunks];

            for (int i = 0; i < numOfChunks; i++) {
                int start = i * MAX_LINE_PER_EFFECT_CELL;
                int length = Math.min(lines.length - start, MAX_LINE_PER_EFFECT_CELL);
                String[] chunkLines = Arrays.copyOfRange(lines, start, start + length);
                chunks[i] = String.join("\n", chunkLines);
            }

            return List.of(chunks);

        }
    }

