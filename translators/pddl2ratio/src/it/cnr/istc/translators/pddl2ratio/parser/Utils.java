/*
 * Copyright (C) 2017 Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package it.cnr.istc.translators.pddl2ratio.parser;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
class Utils {

    private static final String KEYWORDS_EXPR;

    static {
        Keyword[] values = Keyword.values();
        StringBuilder regex = new StringBuilder();
        for (int i = 0; i < values.length; i++) {
            if (i > 0) {
                regex.append("|");
            }
            regex.append(values[i].name);
        }
        KEYWORDS_EXPR = regex.toString();
    }

    static String capitalize(final String str) {
        final char[] buffer = str.toLowerCase().replace('-', '_').toCharArray();
        buffer[0] = Character.toTitleCase(buffer[0]);
        // We don't need to check for keywords since all DDL keywords start lower case..
        return new String(buffer);
    }

    static String lowercase(final String str) {
        final char[] buffer = str.replace('-', '_').toCharArray();
        buffer[0] = Character.toLowerCase(buffer[0]);
        String c_str = new String(buffer);
        // We check for DDL keywords
        if (c_str.matches(KEYWORDS_EXPR)) {
            c_str = "_" + c_str;
        }
        return c_str;
    }

    private Utils() {
    }

    enum Keyword {
        TYPEDEF("typedef"),
        INT("int"),
        REAL("real"),
        BOOL("bool"),
        STRING("string"),
        ENUM("enum"),
        CLASS("class"),
        GOAL("goal"),
        FACT("fact"),
        EXTENDS("extends"),
        PREDICATE("predicate"),
        NEW("new"),
        OR("or"),
        THIS("this"),
        SUPER("super"),
        VOID("void"),
        INF("inf"),
        TRUE("true"),
        FALSE("false"),
        STATE("state"),
        RETURN("return"),
        AT("at"),
        START("start"),
        END("end"),
        DURATION("duration");
        public final String name;

        private Keyword(String name) {
            this.name = name;
        }
    }
}
