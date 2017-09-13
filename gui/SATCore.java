/**
 * SATCore
 */
public class SATCore {

    public SATCore() {
    }

    public void new_var(final long id) {
        System.out.println("new var: " + id);
    }

    public void new_value(final long id, final LBool val) {
        System.out.println("new value (" + id + "): " + val);
    }

    public void new_clause(final long id, Lit[] clause) {
        System.out.println("new clause (" + id + "): " + clause);
    }

    public static class Lit {

        private final long var;
        private final boolean sign;

        public Lit(final long var, final boolean sign) {
            this.var = var;
            this.sign = sign;
        }

        @Override
        public String toString() {
            return (sign ? "" : "-") + var;
        }
    }

    public enum LBool {
        False, True, Undefined
    }
}