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

import java.io.File;
import java.io.IOException;
import org.junit.Assert;
import org.junit.Test;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class TranslatorTest {

    /**
     * Test of blocks world domain.
     */
    @Test
    public void testBlocksWorldParser() {
        try {
            PDDLInstance instance = Translator.parse(new File(TranslatorTest.class.getResource("blocks-domain.pddl").getPath()), new File(TranslatorTest.class.getResource("blocks-problem.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }

    /**
     * Test of new blocks world domain.
     */
    @Test
    public void testNewBlocksWorldParser() {
        try {
            PDDLInstance instance = Translator.parse(new File(TranslatorTest.class.getResource("blocks-domain-new.pddl").getPath()), new File(TranslatorTest.class.getResource("blocks-problem-new.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }

    /**
     * Test of blocks world domain.
     */
    @Test
    public void testLogisticsWorldParser() {
        try {
            PDDLInstance instance = Translator.parse(new File(TranslatorTest.class.getResource("logistics-domain.pddl").getPath()), new File(TranslatorTest.class.getResource("logistics-problem.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }

    /**
     * Test of new blocks world domain.
     */
    @Test
    public void testNewLogisticsWorldParser() {
        try {
            PDDLInstance instance = Translator.parse(new File(TranslatorTest.class.getResource("logistics-domain-new.pddl").getPath()), new File(TranslatorTest.class.getResource("logistics-problem-new.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }

    /**
     * Test of blocks world domain.
     */
    @Test
    public void testBlocksWorldTranslator() {
        try {
            String translation = Translator.translate(new File(TranslatorTest.class.getResource("blocks-domain.pddl").getPath()), new File(TranslatorTest.class.getResource("blocks-problem.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }

    /**
     * Test of new blocks world domain.
     */
    @Test
    public void testNewBlocksWorldTranslator() {
        try {
            String translation = Translator.translate(new File(TranslatorTest.class.getResource("blocks-domain-new.pddl").getPath()), new File(TranslatorTest.class.getResource("blocks-problem-new.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }

    /**
     * Test of blocks world domain.
     */
    @Test
    public void testLogisticsWorldTranslator() {
        try {
            String translation = Translator.translate(new File(TranslatorTest.class.getResource("logistics-domain.pddl").getPath()), new File(TranslatorTest.class.getResource("logistics-problem.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }

    /**
     * Test of new blocks world domain.
     */
    @Test
    public void testNewLogisticsWorldTranslator() {
        try {
            String translation = Translator.translate(new File(TranslatorTest.class.getResource("logistics-domain-new.pddl").getPath()), new File(TranslatorTest.class.getResource("logistics-problem-new.pddl").getPath()));
        } catch (IOException ex) {
            Assert.fail(ex.getMessage());
        }
    }
}
