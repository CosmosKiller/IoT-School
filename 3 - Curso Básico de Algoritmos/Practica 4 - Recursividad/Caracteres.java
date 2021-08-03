public class Caracteres {
    public String reverseString(final String str) {
        if (str.isEmpty()) {
            return str;
        } else {
            return reverseString(str.substring(1)) + str.charAt(0);
        }
    }

    public static void main(final String[] args) {
        final Caracteres obj = new Caracteres();
        final String result = obj.reverseString("Hola papá sos un cra monkey");
        System.out.println(result);
    }
}