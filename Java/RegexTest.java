package Java;
import java.util.regex.*;
public class RegexTest {
    public static void main(String[] args) {
        Pattern p = Pattern.compile("a+");
        String s = "aabbbaaaaabbbabb";
        System.out.println(s.matches("a+b+a+b+a+b+"));
        Matcher m = p.matcher(s);
        while (m.find()) {
            System.out.println(m.start() + "-->" + m.end() + ": " + m.group());
        }
    }
}
