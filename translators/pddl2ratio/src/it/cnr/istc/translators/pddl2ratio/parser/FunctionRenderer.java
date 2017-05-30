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

import it.cnr.istc.translators.pddl2ratio.language.Domain;
import it.cnr.istc.translators.pddl2ratio.language.Function;
import java.util.Locale;
import org.stringtemplate.v4.AttributeRenderer;
import org.stringtemplate.v4.STGroupFile;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
class FunctionRenderer implements AttributeRenderer {

    private final STGroupFile file;
    private final Domain domain;

    FunctionRenderer(STGroupFile file, Domain domain) {
        this.file = file;
        this.domain = domain;
    }

    @Override
    public String toString(Object o, String formatString, Locale locale) {
        Function function = (Function) o;
        StringBuilder sb = new StringBuilder();
        return sb.toString();
    }
}
