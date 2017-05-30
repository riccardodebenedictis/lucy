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
package it.cnr.istc.translators.pddl2ratio.language;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class Type {

    public static final Type OBJECT = new Type("Object");
    public static final Type NUMBER = new Type("number");
    private final String name;
    private Type superclass;
    private final Collection<Constant> instances = new ArrayList<>();

    public Type(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public Type getSuperclass() {
        return superclass;
    }

    public void setSuperclass(Type superclass) {
        this.superclass = superclass;
    }

    public Constant newInstance(String name) {
        Constant instance = new Constant(name, this);
        addInstance(instance);
        return instance;
    }

    private void addInstance(Constant instance) {
        instances.add(instance);
        if (superclass != null) {
            superclass.addInstance(instance);
        }
    }

    public Collection<Constant> getInstances() {
        return Collections.unmodifiableCollection(instances);
    }

    @Override
    public String toString() {
        return name + (superclass != null ? " - " + superclass.name : "");
    }
}
