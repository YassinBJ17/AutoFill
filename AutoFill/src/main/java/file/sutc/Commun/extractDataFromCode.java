package file.sutc.Commun;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class extractDataFromCode {

    public static void main(String[] args) {
        String fileName = "your_file.c";
        List<String> conditions = new ArrayList<>();
        List<String> localVariables = new ArrayList<>();
        List<String> globalVariables = new ArrayList<>();
        List<String> ifStatements = new ArrayList<>();
        List<String> stubs = new ArrayList<>();
        List<String> loops = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            boolean insideFunction = false;
            while ((line = br.readLine()) != null) {
                line = line.replaceAll("//.*|/\\*.*\\*/", "").trim();

                if (!insideFunction && line.matches("\\w+\\s+\\w+\\s*(=\\s*.*)?;")) {
                    globalVariables.add(line);
                }

                if (insideFunction && line.matches("\\w+\\s+\\w+\\s*(=\\s*.*)?;")) {
                    localVariables.add(line);
                }

                if (line.startsWith("if")) {
                    ifStatements.add(line);
                }

                if (line.matches("\\w+\\s+\\w+\\s*\\(.*\\)\\s*;")) {
                    stubs.add(line);
                }

                if (line.startsWith("for") || line.startsWith("while") || line.startsWith("do")) {
                    loops.add(line);
                }

                if (line.matches("\\w+\\s+\\w+\\s*\\(.*\\)\\s*\\{")) {
                    insideFunction = true;
                }
                if (line.contains("}")) {
                    insideFunction = false;
                }

                if (insideFunction && (line.contains("if") || line.contains("for") || line.contains("while"))) {
                    conditions.add(line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }


        System.out.println("Global Variables:");
        globalVariables.forEach(System.out::println);
        System.out.println("\nLocal Variables:");
        localVariables.forEach(System.out::println);
        System.out.println("\nIf Statements:");
        ifStatements.forEach(System.out::println);
        System.out.println("\nStubs:");
        stubs.forEach(System.out::println);
        System.out.println("\nLoops:");
        loops.forEach(System.out::println);
        System.out.println("\nConditions:");
        conditions.forEach(System.out::println);
    }
}
