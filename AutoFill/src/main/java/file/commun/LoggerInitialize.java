package file.commun;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


public class LoggerInitialize {

        public static final Logger logger4j = LogManager.getLogger();



    public static void log4Info(String logging) {
        logger4j.info("\u001B[34m" + logging + "\u001B[0m");
    }

    public static void log4Error(String logging) {
        logger4j.error("\u001B[31m" + logging + "\u001B[0m");
    }

    public static void log4Debug(String logging) {

        logger4j.debug("\u001B[93m" + logging + "\u001B[0m");
    }

    }
