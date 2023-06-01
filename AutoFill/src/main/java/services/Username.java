package services;

public class Username {

    public static String Username_filling(){
        return System.getProperty("user.name").toUpperCase();
    }
}
