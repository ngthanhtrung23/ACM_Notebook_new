package Java;
import javax.script.*;

public class JS {
    public static void main(String[] args) throws Exception {
        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine engine = manager.getEngineByName("JavaScript");

        String s = "(1 + 1) * 2";
        engine.put("s", s);
        engine.eval("print('In JS, s = ' + s); s = eval(s);");

        Integer t = (Integer) engine.get("s");
        System.out.println("In Java, t = " + t);
    }
}
