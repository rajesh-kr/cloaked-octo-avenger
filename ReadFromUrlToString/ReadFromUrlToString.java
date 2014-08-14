import java.util.*;
import java.net.*;
import java.io.*;

public class ReadFromUrlToString {
    public static void main(String[] args) {
        try {
            URL url = new URL("http://www.yahoo.com/");
	    String output = new Scanner(url.openStream(), "UTF-8").useDelimiter("\\A").next();
	    System.out.println(output);
	}
	catch(IOException ie) {
	    ie.printStackTrace();
	}
    }
}
