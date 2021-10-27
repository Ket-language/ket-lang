package com.craftinginterpreters.lox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketPermission;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;

public class Ket {

    static boolean hadError = false;

    // Main
    public static void main(String args[]) throws IOException {
        if(args.length > 1) {
            System.out.println(" <Usage> : ket [script] ");
            System.exit(64);
        }
        else if(args.length == 1) {
            runFile(args[0]);
        }
        else {
            runPrompt();
        }
    }

    // runFile - when a script file is passed
    private static void runFile(String path) throws IOException {
        byte[] bytes = Files.readAllBytes(Paths.get(path));
        run(new String(bytes, Charset.defaultCharset()));
        if (hadError) System.exit(65);
    }

    // runPrompt - CLI mode to run code line by line
    private static void runPrompt() throws IOException {
        InputStreamReader input = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input);

        for(;;) {
            System.out.print(":: ");
            String line = reader.readLine();
            if(line == null) {
                break;
            }
            run(line);
            hadError = false;
        }
    }

    // run fucntion
    private static void run(String source) {
        Scanner scanner = new Scanner(source);
        List<Token> tokens = scanner.scanTokens();

        for (Token token : tokens) {
            System.out.println(token);
        }
    }

    // error function
    static void error(int line, String message) {
        report(line, "", message);
    }

    // report function
    private static void report(int line, String where, String message) {
        System.err.println("[line " + line + "] Error" + where + ": " + message);
        hadError = true;
    }
}