package it.cnr.istc.translators.pddl2ratio.parser;

import java.util.List;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.tree.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class PDDLParser extends Parser {

    static {
        RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION);
    }
    protected static final DFA[] _decisionToDFA;
    protected static final PredictionContextCache _sharedContextCache
            = new PredictionContextCache();
    public static final int DEFINE = 1, DOMAIN = 2, REQUIREMENTS = 3, TYPES = 4, CONSTANTS = 5, PREDICATES = 6,
            FUNCTIONS = 7, NUMBER_TYPE = 8, CONSTRAINTS = 9, OBJECT_TYPE = 10, EITHER = 11,
            ACTION = 12, PARAMETERS = 13, PRECONDITION = 14, EFFECT = 15, AND = 16, OR = 17, NOT = 18,
            IMPLY = 19, EXISTS = 20, FORALL = 21, PREFERENCE = 22, WHEN = 23, ASSIGN = 24, UNDEFINED = 25,
            SCALE_UP = 26, SCALE_DOWN = 27, INCREASE = 28, DECREASE = 29, DURATIVE_ACTION = 30,
            DURATION = 31, CONDITION = 32, AT = 33, OVER = 34, START = 35, END = 36, ALL = 37, DURATION_VARIABLE = 38,
            TIME = 39, DERIVED = 40, PROBLEM = 41, PROBLEM_DOMAIN = 42, OBJECTS = 43, INIT = 44,
            GOAL = 45, ALWAYS = 46, SOMETIME = 47, WITHIN = 48, AT_MOST_ONCE = 49, SOMETIME_AFTER = 50,
            SOMETIME_BEFORE = 51, ALWAYS_WITHIN = 52, HOLD_DURING = 53, HOLD_AFTER = 54, METRIC = 55,
            MINIMIZE = 56, MAXIMIZE = 57, TOTAL_TIME = 58, IS_VIOLATED = 59, LENGTH = 60, SERIAL = 61,
            PARALLEL = 62, STRIPS = 63, TYPING = 64, NEGATIVE_PRECONDITIONS = 65, DISJUNCTIVE_PRECONDITIONS = 66,
            EQUALITY = 67, EXISTENTIAL_PRECONDITIONS = 68, UNIVERSAL_PRECONDITIONS = 69,
            QUANTIFIED_PRECONDITIONS = 70, CONDITIONAL_EFFECTS = 71, FLUENTS = 72, NUMERIC_FLUENTS = 73,
            OBJECT_FLUENTS = 74, ADL = 75, DURATIVE_ACTIONS = 76, DURATION_INEQUALITIES = 77,
            CONTINUOUS_EFFECTS = 78, DERIVED_PREDICATES = 79, TIMED_INITIAL_LITERALS = 80,
            PREFERENCES = 81, ACTION_COSTS = 82, GOAL_UTILITIES = 83, QUESTION = 84, LPAREN = 85,
            RPAREN = 86, PLUS = 87, MINUS = 88, STAR = 89, SLASH = 90, EQUAL = 91, GT = 92, LT = 93,
            LTEQ = 94, GTEQ = 95, NAME = 96, NUMBER = 97, COMMENT = 98, WS = 99;
    public static final int RULE_domain = 0, RULE_require_def = 1, RULE_types_def = 2, RULE_constants_def = 3,
            RULE_predicates_def = 4, RULE_atomic_formula_skeleton = 5, RULE_predicate = 6,
            RULE_variable = 7, RULE_atomic_function_skeleton = 8, RULE_function_symbol = 9,
            RULE_functions_def = 10, RULE_function_typed_list_atomic_function_skeleton = 11,
            RULE_function_type = 12, RULE_constraints = 13, RULE_structure_def = 14,
            RULE_typed_list_name = 15, RULE_typed_list_variable = 16, RULE_primitive_type = 17,
            RULE_type = 18, RULE_emptyOr_pre_GD = 19, RULE_emptyOr_effect = 20, RULE_emptyOr_da_GD = 21,
            RULE_emptyOr_da_effect = 22, RULE_action_def = 23, RULE_action_symbol = 24,
            RULE_action_def_body = 25, RULE_pre_GD = 26, RULE_pref_GD = 27, RULE_pref_name = 28,
            RULE_gD = 29, RULE_f_comp = 30, RULE_literal_term = 31, RULE_literal_name = 32,
            RULE_atomic_formula_term = 33, RULE_atomic_formula_name = 34, RULE_term = 35,
            RULE_function_term = 36, RULE_f_exp = 37, RULE_f_head = 38, RULE_binary_op = 39,
            RULE_multi_op = 40, RULE_binary_comp = 41, RULE_name = 42, RULE_effect = 43,
            RULE_c_effect = 44, RULE_p_effect = 45, RULE_cond_effect = 46, RULE_assign_op = 47,
            RULE_durative_action_def = 48, RULE_da_symbol = 49, RULE_da_def_body = 50,
            RULE_da_GD = 51, RULE_pref_timed_GD = 52, RULE_timed_GD = 53, RULE_time_specifier = 54,
            RULE_interval = 55, RULE_duration_constraint = 56, RULE_simple_duration_constraint = 57,
            RULE_d_op = 58, RULE_d_value = 59, RULE_da_effect = 60, RULE_timed_effect = 61,
            RULE_f_assign_da = 62, RULE_f_exp_da = 63, RULE_assign_op_t = 64, RULE_f_exp_t = 65,
            RULE_derived_def = 66, RULE_problem = 67, RULE_object_declaration = 68,
            RULE_init = 69, RULE_init_el = 70, RULE_basic_function_term = 71, RULE_goal = 72,
            RULE_pref_con_GD = 73, RULE_con_GD = 74, RULE_metric_spec = 75, RULE_optimization = 76,
            RULE_metric_f_exp = 77, RULE_length_spec = 78, RULE_require_key = 79;
    public static final String[] ruleNames = {
        "domain", "require_def", "types_def", "constants_def", "predicates_def",
        "atomic_formula_skeleton", "predicate", "variable", "atomic_function_skeleton",
        "function_symbol", "functions_def", "function_typed_list_atomic_function_skeleton",
        "function_type", "constraints", "structure_def", "typed_list_name", "typed_list_variable",
        "primitive_type", "type", "emptyOr_pre_GD", "emptyOr_effect", "emptyOr_da_GD",
        "emptyOr_da_effect", "action_def", "action_symbol", "action_def_body",
        "pre_GD", "pref_GD", "pref_name", "gD", "f_comp", "literal_term", "literal_name",
        "atomic_formula_term", "atomic_formula_name", "term", "function_term",
        "f_exp", "f_head", "binary_op", "multi_op", "binary_comp", "name", "effect",
        "c_effect", "p_effect", "cond_effect", "assign_op", "durative_action_def",
        "da_symbol", "da_def_body", "da_GD", "pref_timed_GD", "timed_GD", "time_specifier",
        "interval", "duration_constraint", "simple_duration_constraint", "d_op",
        "d_value", "da_effect", "timed_effect", "f_assign_da", "f_exp_da", "assign_op_t",
        "f_exp_t", "derived_def", "problem", "object_declaration", "init", "init_el",
        "basic_function_term", "goal", "pref_con_GD", "con_GD", "metric_spec",
        "optimization", "metric_f_exp", "length_spec", "require_key"
    };
    private static final String[] _LITERAL_NAMES = {
        null, "'define'", "'domain'", "':requirements'", "':types'", "':constants'",
        "':predicates'", "':functions'", "'number'", "':constraints'", "'object'",
        "'either'", "':action'", "':parameters'", "':precondition'", "':effect'",
        "'and'", "'or'", "'not'", "'imply'", "'exists'", "'forall'", "'preference'",
        "'when'", "'assign'", "'undefined'", "'scale-up'", "'scale-down'", "'increase'",
        "'decrease'", "':durative-action'", "':duration'", "':condition'", "'at'",
        "'over'", "'start'", "'end'", "'all'", "'?duration'", "'#t'", "':derived'",
        "'problem'", "':domain'", "':objects'", "':init'", "':goal'", "'always'",
        "'sometime'", "'within'", "'at-most-once'", "'sometime-after'", "'sometime-before'",
        "'always-within'", "'hold-during'", "'hold-after'", "':metric'", "'minimize'",
        "'maximize'", "'total-time'", "'is-violated'", "':length'", "':serial'",
        "':parallel'", "':strips'", "':typing'", "':negative-preconditions'",
        "':disjunctive-preconditions'", "':equality'", "':existential-preconditions'",
        "':universal-preconditions'", "':quantified-preconditions'", "':conditional-effects'",
        "':fluents'", "':numeric-fluents'", "':object-fluents'", "':adl'", "':durative-actions'",
        "':duration-inequalities'", "':continuous-effects'", "':derived-predicates'",
        "':timed-initial-literals'", "':preferences'", "':action-costs'", "':goal-utilities'",
        "'?'", "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'='", "'>'", "'<'",
        "'<='", "'>='"
    };
    private static final String[] _SYMBOLIC_NAMES = {
        null, "DEFINE", "DOMAIN", "REQUIREMENTS", "TYPES", "CONSTANTS", "PREDICATES",
        "FUNCTIONS", "NUMBER_TYPE", "CONSTRAINTS", "OBJECT_TYPE", "EITHER", "ACTION",
        "PARAMETERS", "PRECONDITION", "EFFECT", "AND", "OR", "NOT", "IMPLY", "EXISTS",
        "FORALL", "PREFERENCE", "WHEN", "ASSIGN", "UNDEFINED", "SCALE_UP", "SCALE_DOWN",
        "INCREASE", "DECREASE", "DURATIVE_ACTION", "DURATION", "CONDITION", "AT",
        "OVER", "START", "END", "ALL", "DURATION_VARIABLE", "TIME", "DERIVED",
        "PROBLEM", "PROBLEM_DOMAIN", "OBJECTS", "INIT", "GOAL", "ALWAYS", "SOMETIME",
        "WITHIN", "AT_MOST_ONCE", "SOMETIME_AFTER", "SOMETIME_BEFORE", "ALWAYS_WITHIN",
        "HOLD_DURING", "HOLD_AFTER", "METRIC", "MINIMIZE", "MAXIMIZE", "TOTAL_TIME",
        "IS_VIOLATED", "LENGTH", "SERIAL", "PARALLEL", "STRIPS", "TYPING", "NEGATIVE_PRECONDITIONS",
        "DISJUNCTIVE_PRECONDITIONS", "EQUALITY", "EXISTENTIAL_PRECONDITIONS",
        "UNIVERSAL_PRECONDITIONS", "QUANTIFIED_PRECONDITIONS", "CONDITIONAL_EFFECTS",
        "FLUENTS", "NUMERIC_FLUENTS", "OBJECT_FLUENTS", "ADL", "DURATIVE_ACTIONS",
        "DURATION_INEQUALITIES", "CONTINUOUS_EFFECTS", "DERIVED_PREDICATES", "TIMED_INITIAL_LITERALS",
        "PREFERENCES", "ACTION_COSTS", "GOAL_UTILITIES", "QUESTION", "LPAREN",
        "RPAREN", "PLUS", "MINUS", "STAR", "SLASH", "EQUAL", "GT", "LT", "LTEQ",
        "GTEQ", "NAME", "NUMBER", "COMMENT", "WS"
    };
    public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);
    /**
     * @deprecated Use {@link #VOCABULARY} instead.
     */
    @Deprecated
    public static final String[] tokenNames;

    static {
        tokenNames = new String[_SYMBOLIC_NAMES.length];
        for (int i = 0; i < tokenNames.length; i++) {
            tokenNames[i] = VOCABULARY.getLiteralName(i);
            if (tokenNames[i] == null) {
                tokenNames[i] = VOCABULARY.getSymbolicName(i);
            }

            if (tokenNames[i] == null) {
                tokenNames[i] = "<INVALID>";
            }
        }
    }

    @Override
    @Deprecated
    public String[] getTokenNames() {
        return tokenNames;
    }

    @Override
    public Vocabulary getVocabulary() {
        return VOCABULARY;
    }

    @Override
    public String getGrammarFileName() {
        return "PDDL.g4";
    }

    @Override
    public String[] getRuleNames() {
        return ruleNames;
    }

    @Override
    public String getSerializedATN() {
        return _serializedATN;
    }

    @Override
    public ATN getATN() {
        return _ATN;
    }
    final java.util.Set<String> requirements = new java.util.HashSet<>();

    public PDDLParser(TokenStream input) {
        super(input);
        _interp = new ParserATNSimulator(this, _ATN, _decisionToDFA, _sharedContextCache);
    }

    public static class DomainContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Require_defContext require_def() {
            return getRuleContext(Require_defContext.class, 0);
        }

        public Types_defContext types_def() {
            return getRuleContext(Types_defContext.class, 0);
        }

        public Constants_defContext constants_def() {
            return getRuleContext(Constants_defContext.class, 0);
        }

        public Predicates_defContext predicates_def() {
            return getRuleContext(Predicates_defContext.class, 0);
        }

        public Functions_defContext functions_def() {
            return getRuleContext(Functions_defContext.class, 0);
        }

        public ConstraintsContext constraints() {
            return getRuleContext(ConstraintsContext.class, 0);
        }

        public List<Structure_defContext> structure_def() {
            return getRuleContexts(Structure_defContext.class);
        }

        public Structure_defContext structure_def(int i) {
            return getRuleContext(Structure_defContext.class, i);
        }

        public DomainContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_domain;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDomain(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDomain(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDomain(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final DomainContext domain() throws RecognitionException {
        DomainContext _localctx = new DomainContext(_ctx, getState());
        enterRule(_localctx, 0, RULE_domain);
        try {
            int _alt;
            enterOuterAlt(_localctx, 1);
            {
                setState(160);
                match(LPAREN);
                setState(161);
                match(DEFINE);
                setState(162);
                match(LPAREN);
                setState(163);
                match(DOMAIN);
                setState(164);
                name();
                setState(165);
                match(RPAREN);
                setState(167);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 0, _ctx)) {
                    case 1: {
                        setState(166);
                        require_def();
                    }
                    break;
                }
                setState(170);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 1, _ctx)) {
                    case 1: {
                        setState(169);
                        types_def();
                    }
                    break;
                }
                setState(173);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 2, _ctx)) {
                    case 1: {
                        setState(172);
                        constants_def();
                    }
                    break;
                }
                setState(176);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 3, _ctx)) {
                    case 1: {
                        setState(175);
                        predicates_def();
                    }
                    break;
                }
                setState(179);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 4, _ctx)) {
                    case 1: {
                        setState(178);
                        functions_def();
                    }
                    break;
                }
                setState(182);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 5, _ctx)) {
                    case 1: {
                        setState(181);
                        constraints();
                    }
                    break;
                }
                setState(187);
                _errHandler.sync(this);
                _alt = getInterpreter().adaptivePredict(_input, 6, _ctx);
                while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                    if (_alt == 1) {
                        {
                            {
                                setState(184);
                                structure_def();
                            }
                        }
                    }
                    setState(189);
                    _errHandler.sync(this);
                    _alt = getInterpreter().adaptivePredict(_input, 6, _ctx);
                }
                setState(190);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Require_defContext extends ParserRuleContext {

        public List<Require_keyContext> require_key() {
            return getRuleContexts(Require_keyContext.class);
        }

        public Require_keyContext require_key(int i) {
            return getRuleContext(Require_keyContext.class, i);
        }

        public Require_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_require_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterRequire_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitRequire_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitRequire_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Require_defContext require_def() throws RecognitionException {
        Require_defContext _localctx = new Require_defContext(_ctx, getState());
        enterRule(_localctx, 2, RULE_require_def);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(192);
                match(LPAREN);
                setState(193);
                match(REQUIREMENTS);
                setState(195);
                _errHandler.sync(this);
                _la = _input.LA(1);
                do {
                    {
                        {
                            setState(194);
                            require_key();
                        }
                    }
                    setState(197);
                    _errHandler.sync(this);
                    _la = _input.LA(1);
                } while (_la == CONSTRAINTS || _la == STRIPS || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (TYPING - 64)) | (1L << (NEGATIVE_PRECONDITIONS - 64)) | (1L << (DISJUNCTIVE_PRECONDITIONS - 64)) | (1L << (EQUALITY - 64)) | (1L << (EXISTENTIAL_PRECONDITIONS - 64)) | (1L << (UNIVERSAL_PRECONDITIONS - 64)) | (1L << (QUANTIFIED_PRECONDITIONS - 64)) | (1L << (CONDITIONAL_EFFECTS - 64)) | (1L << (FLUENTS - 64)) | (1L << (NUMERIC_FLUENTS - 64)) | (1L << (OBJECT_FLUENTS - 64)) | (1L << (ADL - 64)) | (1L << (DURATIVE_ACTIONS - 64)) | (1L << (DURATION_INEQUALITIES - 64)) | (1L << (CONTINUOUS_EFFECTS - 64)) | (1L << (DERIVED_PREDICATES - 64)) | (1L << (TIMED_INITIAL_LITERALS - 64)) | (1L << (PREFERENCES - 64)) | (1L << (ACTION_COSTS - 64)) | (1L << (GOAL_UTILITIES - 64)))) != 0));
                setState(199);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Types_defContext extends ParserRuleContext {

        public Typed_list_nameContext typed_list_name() {
            return getRuleContext(Typed_list_nameContext.class, 0);
        }

        public Types_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_types_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTypes_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTypes_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTypes_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Types_defContext types_def() throws RecognitionException {
        Types_defContext _localctx = new Types_defContext(_ctx, getState());
        enterRule(_localctx, 4, RULE_types_def);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(201);
                match(LPAREN);
                setState(202);
                match(TYPES);
                setState(204);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 8, _ctx)) {
                    case 1: {
                        setState(203);
                        typed_list_name();
                    }
                    break;
                }
                setState(206);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Constants_defContext extends ParserRuleContext {

        public Typed_list_nameContext typed_list_name() {
            return getRuleContext(Typed_list_nameContext.class, 0);
        }

        public Constants_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_constants_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterConstants_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitConstants_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitConstants_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Constants_defContext constants_def() throws RecognitionException {
        Constants_defContext _localctx = new Constants_defContext(_ctx, getState());
        enterRule(_localctx, 6, RULE_constants_def);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(208);
                match(LPAREN);
                setState(209);
                match(CONSTANTS);
                setState(211);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 9, _ctx)) {
                    case 1: {
                        setState(210);
                        typed_list_name();
                    }
                    break;
                }
                setState(213);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Predicates_defContext extends ParserRuleContext {

        public List<Atomic_formula_skeletonContext> atomic_formula_skeleton() {
            return getRuleContexts(Atomic_formula_skeletonContext.class);
        }

        public Atomic_formula_skeletonContext atomic_formula_skeleton(int i) {
            return getRuleContext(Atomic_formula_skeletonContext.class, i);
        }

        public Predicates_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_predicates_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPredicates_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPredicates_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPredicates_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Predicates_defContext predicates_def() throws RecognitionException {
        Predicates_defContext _localctx = new Predicates_defContext(_ctx, getState());
        enterRule(_localctx, 8, RULE_predicates_def);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(215);
                match(LPAREN);
                setState(216);
                match(PREDICATES);
                setState(218);
                _errHandler.sync(this);
                _la = _input.LA(1);
                do {
                    {
                        {
                            setState(217);
                            atomic_formula_skeleton();
                        }
                    }
                    setState(220);
                    _errHandler.sync(this);
                    _la = _input.LA(1);
                } while (_la == LPAREN);
                setState(222);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Atomic_formula_skeletonContext extends ParserRuleContext {

        public PredicateContext predicate() {
            return getRuleContext(PredicateContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Atomic_formula_skeletonContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_atomic_formula_skeleton;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAtomic_formula_skeleton(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAtomic_formula_skeleton(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAtomic_formula_skeleton(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Atomic_formula_skeletonContext atomic_formula_skeleton() throws RecognitionException {
        Atomic_formula_skeletonContext _localctx = new Atomic_formula_skeletonContext(_ctx, getState());
        enterRule(_localctx, 10, RULE_atomic_formula_skeleton);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(224);
                match(LPAREN);
                setState(225);
                predicate();
                setState(227);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 11, _ctx)) {
                    case 1: {
                        setState(226);
                        typed_list_variable();
                    }
                    break;
                }
                setState(229);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class PredicateContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public PredicateContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_predicate;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPredicate(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPredicate(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPredicate(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final PredicateContext predicate() throws RecognitionException {
        PredicateContext _localctx = new PredicateContext(_ctx, getState());
        enterRule(_localctx, 12, RULE_predicate);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(231);
                name();
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class VariableContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public VariableContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_variable;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterVariable(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitVariable(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitVariable(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final VariableContext variable() throws RecognitionException {
        VariableContext _localctx = new VariableContext(_ctx, getState());
        enterRule(_localctx, 14, RULE_variable);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(233);
                match(QUESTION);
                setState(234);
                name();
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Atomic_function_skeletonContext extends ParserRuleContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Atomic_function_skeletonContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_atomic_function_skeleton;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAtomic_function_skeleton(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAtomic_function_skeleton(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAtomic_function_skeleton(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Atomic_function_skeletonContext atomic_function_skeleton() throws RecognitionException {
        Atomic_function_skeletonContext _localctx = new Atomic_function_skeletonContext(_ctx, getState());
        enterRule(_localctx, 16, RULE_atomic_function_skeleton);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(236);
                match(LPAREN);
                setState(237);
                function_symbol();
                setState(239);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 12, _ctx)) {
                    case 1: {
                        setState(238);
                        typed_list_variable();
                    }
                    break;
                }
                setState(241);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Function_symbolContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Function_symbolContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_function_symbol;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterFunction_symbol(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitFunction_symbol(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitFunction_symbol(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Function_symbolContext function_symbol() throws RecognitionException {
        Function_symbolContext _localctx = new Function_symbolContext(_ctx, getState());
        enterRule(_localctx, 18, RULE_function_symbol);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(243);
                name();
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Functions_defContext extends ParserRuleContext {

        public Function_typed_list_atomic_function_skeletonContext function_typed_list_atomic_function_skeleton() {
            return getRuleContext(Function_typed_list_atomic_function_skeletonContext.class, 0);
        }

        public Functions_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_functions_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterFunctions_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitFunctions_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitFunctions_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Functions_defContext functions_def() throws RecognitionException {
        Functions_defContext _localctx = new Functions_defContext(_ctx, getState());
        enterRule(_localctx, 20, RULE_functions_def);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(245);
                if (!(requirements.contains(":fluents") || requirements.contains(":numeric-fluents") || requirements.contains(":object-fluents"))) {
                    throw new FailedPredicateException(this, "requirements.contains(\":fluents\") || requirements.contains(\":numeric-fluents\") || requirements.contains(\":object-fluents\")");
                }
                setState(246);
                match(LPAREN);
                setState(247);
                match(FUNCTIONS);
                setState(249);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 13, _ctx)) {
                    case 1: {
                        setState(248);
                        function_typed_list_atomic_function_skeleton();
                    }
                    break;
                }
                setState(251);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Function_typed_list_atomic_function_skeletonContext extends ParserRuleContext {

        public List<Atomic_function_skeletonContext> atomic_function_skeleton() {
            return getRuleContexts(Atomic_function_skeletonContext.class);
        }

        public Atomic_function_skeletonContext atomic_function_skeleton(int i) {
            return getRuleContext(Atomic_function_skeletonContext.class, i);
        }

        public Function_typeContext function_type() {
            return getRuleContext(Function_typeContext.class, 0);
        }

        public Function_typed_list_atomic_function_skeletonContext function_typed_list_atomic_function_skeleton() {
            return getRuleContext(Function_typed_list_atomic_function_skeletonContext.class, 0);
        }

        public Function_typed_list_atomic_function_skeletonContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_function_typed_list_atomic_function_skeleton;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterFunction_typed_list_atomic_function_skeleton(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitFunction_typed_list_atomic_function_skeleton(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitFunction_typed_list_atomic_function_skeleton(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Function_typed_list_atomic_function_skeletonContext function_typed_list_atomic_function_skeleton() throws RecognitionException {
        Function_typed_list_atomic_function_skeletonContext _localctx = new Function_typed_list_atomic_function_skeletonContext(_ctx, getState());
        enterRule(_localctx, 22, RULE_function_typed_list_atomic_function_skeleton);
        int _la;
        try {
            setState(269);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 17, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(253);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(255);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(254);
                                    atomic_function_skeleton();
                                }
                            }
                            setState(257);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while (_la == LPAREN);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(260);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(259);
                                    atomic_function_skeleton();
                                }
                            }
                            setState(262);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while (_la == LPAREN);
                        setState(264);
                        match(MINUS);
                        setState(265);
                        function_type();
                        setState(267);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 16, _ctx)) {
                            case 1: {
                                setState(266);
                                function_typed_list_atomic_function_skeleton();
                            }
                            break;
                        }
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Function_typeContext extends ParserRuleContext {

        public TypeContext type() {
            return getRuleContext(TypeContext.class, 0);
        }

        public Function_typeContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_function_type;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterFunction_type(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitFunction_type(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitFunction_type(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Function_typeContext function_type() throws RecognitionException {
        Function_typeContext _localctx = new Function_typeContext(_ctx, getState());
        enterRule(_localctx, 24, RULE_function_type);
        try {
            setState(275);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 18, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(271);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(272);
                        match(NUMBER_TYPE);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(273);
                        if (!(requirements.contains(":typing") && requirements.contains(":object-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":typing\") && requirements.contains(\":object-fluents\")");
                        }
                        setState(274);
                        type();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class ConstraintsContext extends ParserRuleContext {

        public Con_GDContext con_GD() {
            return getRuleContext(Con_GDContext.class, 0);
        }

        public Pref_con_GDContext pref_con_GD() {
            return getRuleContext(Pref_con_GDContext.class, 0);
        }

        public ConstraintsContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_constraints;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterConstraints(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitConstraints(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitConstraints(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final ConstraintsContext constraints() throws RecognitionException {
        ConstraintsContext _localctx = new ConstraintsContext(_ctx, getState());
        enterRule(_localctx, 26, RULE_constraints);
        try {
            setState(289);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 19, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(277);
                        if (!(requirements.contains(":constraints"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":constraints\")");
                        }
                        setState(278);
                        match(LPAREN);
                        setState(279);
                        match(CONSTRAINTS);
                        setState(280);
                        con_GD();
                        setState(281);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(283);
                        if (!(requirements.contains(":constraints"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":constraints\")");
                        }
                        setState(284);
                        match(LPAREN);
                        setState(285);
                        match(CONSTRAINTS);
                        setState(286);
                        pref_con_GD();
                        setState(287);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Structure_defContext extends ParserRuleContext {

        public Action_defContext action_def() {
            return getRuleContext(Action_defContext.class, 0);
        }

        public Durative_action_defContext durative_action_def() {
            return getRuleContext(Durative_action_defContext.class, 0);
        }

        public Derived_defContext derived_def() {
            return getRuleContext(Derived_defContext.class, 0);
        }

        public Structure_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_structure_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterStructure_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitStructure_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitStructure_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Structure_defContext structure_def() throws RecognitionException {
        Structure_defContext _localctx = new Structure_defContext(_ctx, getState());
        enterRule(_localctx, 28, RULE_structure_def);
        try {
            setState(296);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 20, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(291);
                        action_def();
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(292);
                        if (!(requirements.contains(":durative-actions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":durative-actions\")");
                        }
                        setState(293);
                        durative_action_def();
                    }
                    break;
                case 3:
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(294);
                        if (!(requirements.contains(":derived-predicates"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":derived-predicates\")");
                        }
                        setState(295);
                        derived_def();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Typed_list_nameContext extends ParserRuleContext {

        public List<NameContext> name() {
            return getRuleContexts(NameContext.class);
        }

        public NameContext name(int i) {
            return getRuleContext(NameContext.class, i);
        }

        public TypeContext type() {
            return getRuleContext(TypeContext.class, 0);
        }

        public Typed_list_nameContext typed_list_name() {
            return getRuleContext(Typed_list_nameContext.class, 0);
        }

        public Typed_list_nameContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_typed_list_name;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTyped_list_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTyped_list_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTyped_list_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Typed_list_nameContext typed_list_name() throws RecognitionException {
        Typed_list_nameContext _localctx = new Typed_list_nameContext(_ctx, getState());
        enterRule(_localctx, 30, RULE_typed_list_name);
        int _la;
        try {
            setState(314);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 24, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(299);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(298);
                                    name();
                                }
                            }
                            setState(301);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while (((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0));
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(303);
                        if (!(requirements.contains(":typing"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":typing\")");
                        }
                        setState(305);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(304);
                                    name();
                                }
                            }
                            setState(307);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while (((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0));
                        setState(309);
                        match(MINUS);
                        setState(310);
                        type();
                        setState(312);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 23, _ctx)) {
                            case 1: {
                                setState(311);
                                typed_list_name();
                            }
                            break;
                        }
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Typed_list_variableContext extends ParserRuleContext {

        public List<VariableContext> variable() {
            return getRuleContexts(VariableContext.class);
        }

        public VariableContext variable(int i) {
            return getRuleContext(VariableContext.class, i);
        }

        public TypeContext type() {
            return getRuleContext(TypeContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Typed_list_variableContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_typed_list_variable;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTyped_list_variable(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTyped_list_variable(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTyped_list_variable(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Typed_list_variableContext typed_list_variable() throws RecognitionException {
        Typed_list_variableContext _localctx = new Typed_list_variableContext(_ctx, getState());
        enterRule(_localctx, 32, RULE_typed_list_variable);
        int _la;
        try {
            setState(332);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 28, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(317);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(316);
                                    variable();
                                }
                            }
                            setState(319);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while (_la == QUESTION);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(321);
                        if (!(requirements.contains(":typing"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":typing\")");
                        }
                        setState(323);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(322);
                                    variable();
                                }
                            }
                            setState(325);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while (_la == QUESTION);
                        setState(327);
                        match(MINUS);
                        setState(328);
                        type();
                        setState(330);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 27, _ctx)) {
                            case 1: {
                                setState(329);
                                typed_list_variable();
                            }
                            break;
                        }
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Primitive_typeContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Primitive_typeContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_primitive_type;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPrimitive_type(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPrimitive_type(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPrimitive_type(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Primitive_typeContext primitive_type() throws RecognitionException {
        Primitive_typeContext _localctx = new Primitive_typeContext(_ctx, getState());
        enterRule(_localctx, 34, RULE_primitive_type);
        try {
            setState(336);
            _errHandler.sync(this);
            switch (_input.LA(1)) {
                case AT:
                case OVER:
                case NAME:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(334);
                        name();
                    }
                    break;
                case OBJECT_TYPE:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(335);
                        match(OBJECT_TYPE);
                    }
                    break;
                default:
                    throw new NoViableAltException(this);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class TypeContext extends ParserRuleContext {

        public List<Primitive_typeContext> primitive_type() {
            return getRuleContexts(Primitive_typeContext.class);
        }

        public Primitive_typeContext primitive_type(int i) {
            return getRuleContext(Primitive_typeContext.class, i);
        }

        public TypeContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_type;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterType(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitType(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitType(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final TypeContext type() throws RecognitionException {
        TypeContext _localctx = new TypeContext(_ctx, getState());
        enterRule(_localctx, 36, RULE_type);
        int _la;
        try {
            setState(348);
            _errHandler.sync(this);
            switch (_input.LA(1)) {
                case LPAREN:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(338);
                        match(LPAREN);
                        setState(339);
                        match(EITHER);
                        setState(341);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(340);
                                    primitive_type();
                                }
                            }
                            setState(343);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << OBJECT_TYPE) | (1L << AT) | (1L << OVER))) != 0) || _la == NAME);
                        setState(345);
                        match(RPAREN);
                    }
                    break;
                case OBJECT_TYPE:
                case AT:
                case OVER:
                case NAME:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(347);
                        primitive_type();
                    }
                    break;
                default:
                    throw new NoViableAltException(this);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class EmptyOr_pre_GDContext extends ParserRuleContext {

        public Pre_GDContext pre_GD() {
            return getRuleContext(Pre_GDContext.class, 0);
        }

        public EmptyOr_pre_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_emptyOr_pre_GD;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterEmptyOr_pre_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitEmptyOr_pre_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitEmptyOr_pre_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final EmptyOr_pre_GDContext emptyOr_pre_GD() throws RecognitionException {
        EmptyOr_pre_GDContext _localctx = new EmptyOr_pre_GDContext(_ctx, getState());
        enterRule(_localctx, 38, RULE_emptyOr_pre_GD);
        try {
            setState(353);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 32, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(350);
                        match(LPAREN);
                        setState(351);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(352);
                        pre_GD();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class EmptyOr_effectContext extends ParserRuleContext {

        public EffectContext effect() {
            return getRuleContext(EffectContext.class, 0);
        }

        public EmptyOr_effectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_emptyOr_effect;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterEmptyOr_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitEmptyOr_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitEmptyOr_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final EmptyOr_effectContext emptyOr_effect() throws RecognitionException {
        EmptyOr_effectContext _localctx = new EmptyOr_effectContext(_ctx, getState());
        enterRule(_localctx, 40, RULE_emptyOr_effect);
        try {
            setState(358);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 33, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(355);
                        match(LPAREN);
                        setState(356);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(357);
                        effect();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class EmptyOr_da_GDContext extends ParserRuleContext {

        public Da_GDContext da_GD() {
            return getRuleContext(Da_GDContext.class, 0);
        }

        public EmptyOr_da_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_emptyOr_da_GD;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterEmptyOr_da_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitEmptyOr_da_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitEmptyOr_da_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final EmptyOr_da_GDContext emptyOr_da_GD() throws RecognitionException {
        EmptyOr_da_GDContext _localctx = new EmptyOr_da_GDContext(_ctx, getState());
        enterRule(_localctx, 42, RULE_emptyOr_da_GD);
        try {
            setState(363);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 34, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(360);
                        match(LPAREN);
                        setState(361);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(362);
                        da_GD();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class EmptyOr_da_effectContext extends ParserRuleContext {

        public Da_effectContext da_effect() {
            return getRuleContext(Da_effectContext.class, 0);
        }

        public EmptyOr_da_effectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_emptyOr_da_effect;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterEmptyOr_da_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitEmptyOr_da_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitEmptyOr_da_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final EmptyOr_da_effectContext emptyOr_da_effect() throws RecognitionException {
        EmptyOr_da_effectContext _localctx = new EmptyOr_da_effectContext(_ctx, getState());
        enterRule(_localctx, 44, RULE_emptyOr_da_effect);
        try {
            setState(368);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 35, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(365);
                        match(LPAREN);
                        setState(366);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(367);
                        da_effect();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Action_defContext extends ParserRuleContext {

        public Action_symbolContext action_symbol() {
            return getRuleContext(Action_symbolContext.class, 0);
        }

        public Action_def_bodyContext action_def_body() {
            return getRuleContext(Action_def_bodyContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Action_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_action_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAction_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAction_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAction_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Action_defContext action_def() throws RecognitionException {
        Action_defContext _localctx = new Action_defContext(_ctx, getState());
        enterRule(_localctx, 46, RULE_action_def);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(370);
                match(LPAREN);
                setState(371);
                match(ACTION);
                setState(372);
                action_symbol();
                setState(373);
                match(PARAMETERS);
                setState(374);
                match(LPAREN);
                setState(376);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 36, _ctx)) {
                    case 1: {
                        setState(375);
                        typed_list_variable();
                    }
                    break;
                }
                setState(378);
                match(RPAREN);
                setState(379);
                action_def_body();
                setState(380);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Action_symbolContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Action_symbolContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_action_symbol;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAction_symbol(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAction_symbol(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAction_symbol(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Action_symbolContext action_symbol() throws RecognitionException {
        Action_symbolContext _localctx = new Action_symbolContext(_ctx, getState());
        enterRule(_localctx, 48, RULE_action_symbol);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(382);
                name();
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Action_def_bodyContext extends ParserRuleContext {

        public EmptyOr_pre_GDContext emptyOr_pre_GD() {
            return getRuleContext(EmptyOr_pre_GDContext.class, 0);
        }

        public EmptyOr_effectContext emptyOr_effect() {
            return getRuleContext(EmptyOr_effectContext.class, 0);
        }

        public Action_def_bodyContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_action_def_body;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAction_def_body(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAction_def_body(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAction_def_body(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Action_def_bodyContext action_def_body() throws RecognitionException {
        Action_def_bodyContext _localctx = new Action_def_bodyContext(_ctx, getState());
        enterRule(_localctx, 50, RULE_action_def_body);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(386);
                _errHandler.sync(this);
                _la = _input.LA(1);
                if (_la == PRECONDITION) {
                    {
                        setState(384);
                        match(PRECONDITION);
                        setState(385);
                        emptyOr_pre_GD();
                    }
                }

                setState(390);
                _errHandler.sync(this);
                _la = _input.LA(1);
                if (_la == EFFECT) {
                    {
                        setState(388);
                        match(EFFECT);
                        setState(389);
                        emptyOr_effect();
                    }
                }

            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Pre_GDContext extends ParserRuleContext {

        public Pre_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_pre_GD;
        }

        public Pre_GDContext() {
        }

        public void copyFrom(Pre_GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Pre_GD_pref_GDContext extends Pre_GDContext {

        public Pref_GDContext pref_GD() {
            return getRuleContext(Pref_GDContext.class, 0);
        }

        public Pre_GD_pref_GDContext(Pre_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPre_GD_pref_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPre_GD_pref_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPre_GD_pref_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Pre_GD_andContext extends Pre_GDContext {

        public List<Pre_GDContext> pre_GD() {
            return getRuleContexts(Pre_GDContext.class);
        }

        public Pre_GDContext pre_GD(int i) {
            return getRuleContext(Pre_GDContext.class, i);
        }

        public Pre_GD_andContext(Pre_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPre_GD_and(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPre_GD_and(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPre_GD_and(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Pre_GD_forallContext extends Pre_GDContext {

        public Pre_GDContext pre_GD() {
            return getRuleContext(Pre_GDContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Pre_GD_forallContext(Pre_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPre_GD_forall(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPre_GD_forall(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPre_GD_forall(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Pre_GDContext pre_GD() throws RecognitionException {
        Pre_GDContext _localctx = new Pre_GDContext(_ctx, getState());
        enterRule(_localctx, 52, RULE_pre_GD);
        try {
            int _alt;
            setState(413);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 41, _ctx)) {
                case 1:
                    _localctx = new Pre_GD_pref_GDContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(392);
                        pref_GD();
                    }
                    break;
                case 2:
                    _localctx = new Pre_GD_andContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(393);
                        match(LPAREN);
                        setState(394);
                        match(AND);
                        setState(398);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 39, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(395);
                                        pre_GD();
                                    }
                                }
                            }
                            setState(400);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 39, _ctx);
                        }
                        setState(401);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Pre_GD_forallContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(402);
                        if (!(requirements.contains(":universal-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":universal-preconditions\")");
                        }
                        setState(403);
                        match(LPAREN);
                        setState(404);
                        match(FORALL);
                        setState(405);
                        match(LPAREN);
                        setState(407);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 40, _ctx)) {
                            case 1: {
                                setState(406);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(409);
                        match(RPAREN);
                        setState(410);
                        pre_GD();
                        setState(411);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Pref_GDContext extends ParserRuleContext {

        public Pref_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_pref_GD;
        }

        public Pref_GDContext() {
        }

        public void copyFrom(Pref_GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Pref_GD_gDContext extends Pref_GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Pref_GD_gDContext(Pref_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_GD_gD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_GD_gD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_GD_gD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Pref_GD_preference_gDContext extends Pref_GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Pref_nameContext pref_name() {
            return getRuleContext(Pref_nameContext.class, 0);
        }

        public Pref_GD_preference_gDContext(Pref_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_GD_preference_gD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_GD_preference_gD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_GD_preference_gD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Pref_GDContext pref_GD() throws RecognitionException {
        Pref_GDContext _localctx = new Pref_GDContext(_ctx, getState());
        enterRule(_localctx, 54, RULE_pref_GD);
        try {
            setState(425);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 43, _ctx)) {
                case 1:
                    _localctx = new Pref_GD_preference_gDContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(415);
                        if (!(requirements.contains(":preferences"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":preferences\")");
                        }
                        setState(416);
                        match(LPAREN);
                        setState(417);
                        match(PREFERENCE);
                        setState(419);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 42, _ctx)) {
                            case 1: {
                                setState(418);
                                pref_name();
                            }
                            break;
                        }
                        setState(421);
                        gD();
                        setState(422);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Pref_GD_gDContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(424);
                        gD();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Pref_nameContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Pref_nameContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_pref_name;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Pref_nameContext pref_name() throws RecognitionException {
        Pref_nameContext _localctx = new Pref_nameContext(_ctx, getState());
        enterRule(_localctx, 56, RULE_pref_name);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(427);
                name();
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class GDContext extends ParserRuleContext {

        public GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_gD;
        }

        public GDContext() {
        }

        public void copyFrom(GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Gd_literal_termContext extends GDContext {

        public Literal_termContext literal_term() {
            return getRuleContext(Literal_termContext.class, 0);
        }

        public Gd_literal_termContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_literal_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_literal_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_literal_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_notContext extends GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Gd_notContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_not(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_not(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_not(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_atomic_formula_termContext extends GDContext {

        public Atomic_formula_termContext atomic_formula_term() {
            return getRuleContext(Atomic_formula_termContext.class, 0);
        }

        public Gd_atomic_formula_termContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_atomic_formula_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_atomic_formula_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_atomic_formula_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_andContext extends GDContext {

        public List<GDContext> gD() {
            return getRuleContexts(GDContext.class);
        }

        public GDContext gD(int i) {
            return getRuleContext(GDContext.class, i);
        }

        public Gd_andContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_and(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_and(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_and(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_forallContext extends GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Gd_forallContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_forall(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_forall(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_forall(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_implyContext extends GDContext {

        public List<GDContext> gD() {
            return getRuleContexts(GDContext.class);
        }

        public GDContext gD(int i) {
            return getRuleContext(GDContext.class, i);
        }

        public Gd_implyContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_imply(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_imply(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_imply(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_existsContext extends GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Gd_existsContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_exists(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_exists(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_exists(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_orContext extends GDContext {

        public List<GDContext> gD() {
            return getRuleContexts(GDContext.class);
        }

        public GDContext gD(int i) {
            return getRuleContext(GDContext.class, i);
        }

        public Gd_orContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_or(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_or(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_or(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Gd_f_compContext extends GDContext {

        public F_compContext f_comp() {
            return getRuleContext(F_compContext.class, 0);
        }

        public Gd_f_compContext(GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGd_f_comp(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGd_f_comp(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGd_f_comp(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final GDContext gD() throws RecognitionException {
        GDContext _localctx = new GDContext(_ctx, getState());
        enterRule(_localctx, 58, RULE_gD);
        try {
            int _alt;
            setState(488);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 48, _ctx)) {
                case 1:
                    _localctx = new Gd_atomic_formula_termContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(429);
                        atomic_formula_term();
                    }
                    break;
                case 2:
                    _localctx = new Gd_literal_termContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(430);
                        if (!(requirements.contains(":negative-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":negative-preconditions\")");
                        }
                        setState(431);
                        literal_term();
                    }
                    break;
                case 3:
                    _localctx = new Gd_andContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(432);
                        match(LPAREN);
                        setState(433);
                        match(AND);
                        setState(437);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 44, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(434);
                                        gD();
                                    }
                                }
                            }
                            setState(439);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 44, _ctx);
                        }
                        setState(440);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new Gd_orContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(441);
                        if (!(requirements.contains(":disjunctive-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":disjunctive-preconditions\")");
                        }
                        setState(442);
                        match(LPAREN);
                        setState(443);
                        match(OR);
                        setState(447);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 45, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(444);
                                        gD();
                                    }
                                }
                            }
                            setState(449);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 45, _ctx);
                        }
                        setState(450);
                        match(RPAREN);
                    }
                    break;
                case 5:
                    _localctx = new Gd_notContext(_localctx);
                    enterOuterAlt(_localctx, 5);
                     {
                        setState(451);
                        if (!(requirements.contains(":disjunctive-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":disjunctive-preconditions\")");
                        }
                        setState(452);
                        match(LPAREN);
                        setState(453);
                        match(NOT);
                        setState(454);
                        gD();
                        setState(455);
                        match(RPAREN);
                    }
                    break;
                case 6:
                    _localctx = new Gd_implyContext(_localctx);
                    enterOuterAlt(_localctx, 6);
                     {
                        setState(457);
                        if (!(requirements.contains(":disjunctive-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":disjunctive-preconditions\")");
                        }
                        setState(458);
                        match(LPAREN);
                        setState(459);
                        match(IMPLY);
                        setState(460);
                        gD();
                        setState(461);
                        gD();
                        setState(462);
                        match(RPAREN);
                    }
                    break;
                case 7:
                    _localctx = new Gd_existsContext(_localctx);
                    enterOuterAlt(_localctx, 7);
                     {
                        setState(464);
                        if (!(requirements.contains(":existential-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":existential-preconditions\")");
                        }
                        setState(465);
                        match(LPAREN);
                        setState(466);
                        match(EXISTS);
                        setState(467);
                        match(LPAREN);
                        setState(469);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 46, _ctx)) {
                            case 1: {
                                setState(468);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(471);
                        match(RPAREN);
                        setState(472);
                        gD();
                        setState(473);
                        match(RPAREN);
                    }
                    break;
                case 8:
                    _localctx = new Gd_forallContext(_localctx);
                    enterOuterAlt(_localctx, 8);
                     {
                        setState(475);
                        if (!(requirements.contains(":universal-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":universal-preconditions\")");
                        }
                        setState(476);
                        match(LPAREN);
                        setState(477);
                        match(FORALL);
                        setState(478);
                        match(LPAREN);
                        setState(480);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 47, _ctx)) {
                            case 1: {
                                setState(479);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(482);
                        match(RPAREN);
                        setState(483);
                        gD();
                        setState(484);
                        match(RPAREN);
                    }
                    break;
                case 9:
                    _localctx = new Gd_f_compContext(_localctx);
                    enterOuterAlt(_localctx, 9);
                     {
                        setState(486);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(487);
                        f_comp();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class F_compContext extends ParserRuleContext {

        public Binary_compContext binary_comp() {
            return getRuleContext(Binary_compContext.class, 0);
        }

        public List<F_expContext> f_exp() {
            return getRuleContexts(F_expContext.class);
        }

        public F_expContext f_exp(int i) {
            return getRuleContext(F_expContext.class, i);
        }

        public F_compContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_f_comp;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_comp(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_comp(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_comp(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final F_compContext f_comp() throws RecognitionException {
        F_compContext _localctx = new F_compContext(_ctx, getState());
        enterRule(_localctx, 60, RULE_f_comp);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(490);
                match(LPAREN);
                setState(491);
                binary_comp();
                setState(492);
                f_exp();
                setState(493);
                f_exp();
                setState(494);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Literal_termContext extends ParserRuleContext {

        public Literal_termContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_literal_term;
        }

        public Literal_termContext() {
        }

        public void copyFrom(Literal_termContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Literal_term_atomic_formula_termContext extends Literal_termContext {

        public Atomic_formula_termContext atomic_formula_term() {
            return getRuleContext(Atomic_formula_termContext.class, 0);
        }

        public Literal_term_atomic_formula_termContext(Literal_termContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterLiteral_term_atomic_formula_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitLiteral_term_atomic_formula_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitLiteral_term_atomic_formula_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Literal_term_not_atomic_formula_termContext extends Literal_termContext {

        public Atomic_formula_termContext atomic_formula_term() {
            return getRuleContext(Atomic_formula_termContext.class, 0);
        }

        public Literal_term_not_atomic_formula_termContext(Literal_termContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterLiteral_term_not_atomic_formula_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitLiteral_term_not_atomic_formula_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitLiteral_term_not_atomic_formula_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Literal_termContext literal_term() throws RecognitionException {
        Literal_termContext _localctx = new Literal_termContext(_ctx, getState());
        enterRule(_localctx, 62, RULE_literal_term);
        try {
            setState(502);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 49, _ctx)) {
                case 1:
                    _localctx = new Literal_term_atomic_formula_termContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(496);
                        atomic_formula_term();
                    }
                    break;
                case 2:
                    _localctx = new Literal_term_not_atomic_formula_termContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(497);
                        match(LPAREN);
                        setState(498);
                        match(NOT);
                        setState(499);
                        atomic_formula_term();
                        setState(500);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Literal_nameContext extends ParserRuleContext {

        public Literal_nameContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_literal_name;
        }

        public Literal_nameContext() {
        }

        public void copyFrom(Literal_nameContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Literal_name_atomic_formula_nameContext extends Literal_nameContext {

        public Atomic_formula_nameContext atomic_formula_name() {
            return getRuleContext(Atomic_formula_nameContext.class, 0);
        }

        public Literal_name_atomic_formula_nameContext(Literal_nameContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterLiteral_name_atomic_formula_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitLiteral_name_atomic_formula_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitLiteral_name_atomic_formula_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Literal_name_not_atomic_formula_nameContext extends Literal_nameContext {

        public Atomic_formula_nameContext atomic_formula_name() {
            return getRuleContext(Atomic_formula_nameContext.class, 0);
        }

        public Literal_name_not_atomic_formula_nameContext(Literal_nameContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterLiteral_name_not_atomic_formula_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitLiteral_name_not_atomic_formula_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitLiteral_name_not_atomic_formula_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Literal_nameContext literal_name() throws RecognitionException {
        Literal_nameContext _localctx = new Literal_nameContext(_ctx, getState());
        enterRule(_localctx, 64, RULE_literal_name);
        try {
            setState(510);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 50, _ctx)) {
                case 1:
                    _localctx = new Literal_name_atomic_formula_nameContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(504);
                        atomic_formula_name();
                    }
                    break;
                case 2:
                    _localctx = new Literal_name_not_atomic_formula_nameContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(505);
                        match(LPAREN);
                        setState(506);
                        match(NOT);
                        setState(507);
                        atomic_formula_name();
                        setState(508);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Atomic_formula_termContext extends ParserRuleContext {

        public Atomic_formula_termContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_atomic_formula_term;
        }

        public Atomic_formula_termContext() {
        }

        public void copyFrom(Atomic_formula_termContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Atomic_formula_term_eqContext extends Atomic_formula_termContext {

        public List<TermContext> term() {
            return getRuleContexts(TermContext.class);
        }

        public TermContext term(int i) {
            return getRuleContext(TermContext.class, i);
        }

        public Atomic_formula_term_eqContext(Atomic_formula_termContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAtomic_formula_term_eq(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAtomic_formula_term_eq(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAtomic_formula_term_eq(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Atomic_formula_term_predicateContext extends Atomic_formula_termContext {

        public PredicateContext predicate() {
            return getRuleContext(PredicateContext.class, 0);
        }

        public List<TermContext> term() {
            return getRuleContexts(TermContext.class);
        }

        public TermContext term(int i) {
            return getRuleContext(TermContext.class, i);
        }

        public Atomic_formula_term_predicateContext(Atomic_formula_termContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAtomic_formula_term_predicate(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAtomic_formula_term_predicate(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAtomic_formula_term_predicate(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Atomic_formula_termContext atomic_formula_term() throws RecognitionException {
        Atomic_formula_termContext _localctx = new Atomic_formula_termContext(_ctx, getState());
        enterRule(_localctx, 66, RULE_atomic_formula_term);
        try {
            int _alt;
            setState(529);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 52, _ctx)) {
                case 1:
                    _localctx = new Atomic_formula_term_predicateContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(512);
                        match(LPAREN);
                        setState(513);
                        predicate();
                        setState(517);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 51, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(514);
                                        term();
                                    }
                                }
                            }
                            setState(519);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 51, _ctx);
                        }
                        setState(520);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Atomic_formula_term_eqContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(522);
                        if (!(requirements.contains(":equality"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":equality\")");
                        }
                        setState(523);
                        match(LPAREN);
                        setState(524);
                        match(EQUAL);
                        setState(525);
                        term();
                        setState(526);
                        term();
                        setState(527);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Atomic_formula_nameContext extends ParserRuleContext {

        public Atomic_formula_nameContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_atomic_formula_name;
        }

        public Atomic_formula_nameContext() {
        }

        public void copyFrom(Atomic_formula_nameContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Atomic_formula_name_predicateContext extends Atomic_formula_nameContext {

        public PredicateContext predicate() {
            return getRuleContext(PredicateContext.class, 0);
        }

        public List<NameContext> name() {
            return getRuleContexts(NameContext.class);
        }

        public NameContext name(int i) {
            return getRuleContext(NameContext.class, i);
        }

        public Atomic_formula_name_predicateContext(Atomic_formula_nameContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAtomic_formula_name_predicate(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAtomic_formula_name_predicate(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAtomic_formula_name_predicate(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Atomic_formula_name_eqContext extends Atomic_formula_nameContext {

        public List<NameContext> name() {
            return getRuleContexts(NameContext.class);
        }

        public NameContext name(int i) {
            return getRuleContext(NameContext.class, i);
        }

        public Atomic_formula_name_eqContext(Atomic_formula_nameContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAtomic_formula_name_eq(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAtomic_formula_name_eq(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAtomic_formula_name_eq(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Atomic_formula_nameContext atomic_formula_name() throws RecognitionException {
        Atomic_formula_nameContext _localctx = new Atomic_formula_nameContext(_ctx, getState());
        enterRule(_localctx, 68, RULE_atomic_formula_name);
        int _la;
        try {
            setState(548);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 54, _ctx)) {
                case 1:
                    _localctx = new Atomic_formula_name_predicateContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(531);
                        match(LPAREN);
                        setState(532);
                        predicate();
                        setState(536);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        while (((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0)) {
                            {
                                {
                                    setState(533);
                                    name();
                                }
                            }
                            setState(538);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        }
                        setState(539);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Atomic_formula_name_eqContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(541);
                        if (!(requirements.contains(":equality"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":equality\")");
                        }
                        setState(542);
                        match(LPAREN);
                        setState(543);
                        match(EQUAL);
                        setState(544);
                        name();
                        setState(545);
                        name();
                        setState(546);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class TermContext extends ParserRuleContext {

        public TermContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_term;
        }

        public TermContext() {
        }

        public void copyFrom(TermContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Term_nameContext extends TermContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Term_nameContext(TermContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTerm_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTerm_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTerm_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Term_variableContext extends TermContext {

        public VariableContext variable() {
            return getRuleContext(VariableContext.class, 0);
        }

        public Term_variableContext(TermContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTerm_variable(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTerm_variable(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTerm_variable(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Term_functionContext extends TermContext {

        public Function_termContext function_term() {
            return getRuleContext(Function_termContext.class, 0);
        }

        public Term_functionContext(TermContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTerm_function(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTerm_function(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTerm_function(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final TermContext term() throws RecognitionException {
        TermContext _localctx = new TermContext(_ctx, getState());
        enterRule(_localctx, 70, RULE_term);
        try {
            setState(554);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 55, _ctx)) {
                case 1:
                    _localctx = new Term_nameContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(550);
                        name();
                    }
                    break;
                case 2:
                    _localctx = new Term_variableContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(551);
                        variable();
                    }
                    break;
                case 3:
                    _localctx = new Term_functionContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(552);
                        if (!(requirements.contains(":object-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":object-fluents\")");
                        }
                        setState(553);
                        function_term();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Function_termContext extends ParserRuleContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public List<TermContext> term() {
            return getRuleContexts(TermContext.class);
        }

        public TermContext term(int i) {
            return getRuleContext(TermContext.class, i);
        }

        public Function_termContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_function_term;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterFunction_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitFunction_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitFunction_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Function_termContext function_term() throws RecognitionException {
        Function_termContext _localctx = new Function_termContext(_ctx, getState());
        enterRule(_localctx, 72, RULE_function_term);
        try {
            int _alt;
            enterOuterAlt(_localctx, 1);
            {
                setState(556);
                if (!(requirements.contains(":object-fluents"))) {
                    throw new FailedPredicateException(this, "requirements.contains(\":object-fluents\")");
                }
                setState(557);
                match(LPAREN);
                setState(558);
                function_symbol();
                setState(562);
                _errHandler.sync(this);
                _alt = getInterpreter().adaptivePredict(_input, 56, _ctx);
                while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                    if (_alt == 1) {
                        {
                            {
                                setState(559);
                                term();
                            }
                        }
                    }
                    setState(564);
                    _errHandler.sync(this);
                    _alt = getInterpreter().adaptivePredict(_input, 56, _ctx);
                }
                setState(565);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class F_expContext extends ParserRuleContext {

        public F_expContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_f_exp;
        }

        public F_expContext() {
        }

        public void copyFrom(F_expContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class F_exp_minusContext extends F_expContext {

        public F_expContext f_exp() {
            return getRuleContext(F_expContext.class, 0);
        }

        public F_exp_minusContext(F_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_minus(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_minus(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_minus(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_numberContext extends F_expContext {

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public F_exp_numberContext(F_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_number(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_number(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_number(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_binary_opContext extends F_expContext {

        public Binary_opContext binary_op() {
            return getRuleContext(Binary_opContext.class, 0);
        }

        public List<F_expContext> f_exp() {
            return getRuleContexts(F_expContext.class);
        }

        public F_expContext f_exp(int i) {
            return getRuleContext(F_expContext.class, i);
        }

        public F_exp_binary_opContext(F_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_binary_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_binary_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_binary_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_multi_opContext extends F_expContext {

        public Multi_opContext multi_op() {
            return getRuleContext(Multi_opContext.class, 0);
        }

        public List<F_expContext> f_exp() {
            return getRuleContexts(F_expContext.class);
        }

        public F_expContext f_exp(int i) {
            return getRuleContext(F_expContext.class, i);
        }

        public F_exp_multi_opContext(F_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_multi_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_multi_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_multi_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_f_headContext extends F_expContext {

        public F_headContext f_head() {
            return getRuleContext(F_headContext.class, 0);
        }

        public F_exp_f_headContext(F_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_f_head(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_f_head(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_f_head(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final F_expContext f_exp() throws RecognitionException {
        F_expContext _localctx = new F_expContext(_ctx, getState());
        enterRule(_localctx, 74, RULE_f_exp);
        try {
            int _alt;
            setState(595);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 58, _ctx)) {
                case 1:
                    _localctx = new F_exp_numberContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(567);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(568);
                        match(NUMBER);
                    }
                    break;
                case 2:
                    _localctx = new F_exp_binary_opContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(569);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(570);
                        match(LPAREN);
                        setState(571);
                        binary_op();
                        setState(572);
                        f_exp();
                        setState(573);
                        f_exp();
                        setState(574);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new F_exp_multi_opContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(576);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(577);
                        match(LPAREN);
                        setState(578);
                        multi_op();
                        setState(579);
                        f_exp();
                        setState(581);
                        _errHandler.sync(this);
                        _alt = 1;
                        do {
                            switch (_alt) {
                                case 1: {
                                    {
                                        setState(580);
                                        f_exp();
                                    }
                                }
                                break;
                                default:
                                    throw new NoViableAltException(this);
                            }
                            setState(583);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 57, _ctx);
                        } while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER);
                        setState(585);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new F_exp_minusContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(587);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(588);
                        match(LPAREN);
                        setState(589);
                        match(MINUS);
                        setState(590);
                        f_exp();
                        setState(591);
                        match(RPAREN);
                    }
                    break;
                case 5:
                    _localctx = new F_exp_f_headContext(_localctx);
                    enterOuterAlt(_localctx, 5);
                     {
                        setState(593);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(594);
                        f_head();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class F_headContext extends ParserRuleContext {

        public F_headContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_f_head;
        }

        public F_headContext() {
        }

        public void copyFrom(F_headContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class F_head_function_symbol_termsContext extends F_headContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public List<TermContext> term() {
            return getRuleContexts(TermContext.class);
        }

        public TermContext term(int i) {
            return getRuleContext(TermContext.class, i);
        }

        public F_head_function_symbol_termsContext(F_headContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_head_function_symbol_terms(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_head_function_symbol_terms(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_head_function_symbol_terms(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_head_function_symbolContext extends F_headContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public F_head_function_symbolContext(F_headContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_head_function_symbol(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_head_function_symbol(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_head_function_symbol(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final F_headContext f_head() throws RecognitionException {
        F_headContext _localctx = new F_headContext(_ctx, getState());
        enterRule(_localctx, 76, RULE_f_head);
        try {
            int _alt;
            setState(608);
            _errHandler.sync(this);
            switch (_input.LA(1)) {
                case LPAREN:
                    _localctx = new F_head_function_symbol_termsContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(597);
                        match(LPAREN);
                        setState(598);
                        function_symbol();
                        setState(602);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 59, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(599);
                                        term();
                                    }
                                }
                            }
                            setState(604);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 59, _ctx);
                        }
                        setState(605);
                        match(RPAREN);
                    }
                    break;
                case AT:
                case OVER:
                case NAME:
                    _localctx = new F_head_function_symbolContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(607);
                        function_symbol();
                    }
                    break;
                default:
                    throw new NoViableAltException(this);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Binary_opContext extends ParserRuleContext {

        public Multi_opContext multi_op() {
            return getRuleContext(Multi_opContext.class, 0);
        }

        public Binary_opContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_binary_op;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterBinary_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitBinary_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitBinary_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Binary_opContext binary_op() throws RecognitionException {
        Binary_opContext _localctx = new Binary_opContext(_ctx, getState());
        enterRule(_localctx, 78, RULE_binary_op);
        int _la;
        try {
            setState(612);
            _errHandler.sync(this);
            switch (_input.LA(1)) {
                case PLUS:
                case STAR:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(610);
                        multi_op();
                    }
                    break;
                case MINUS:
                case SLASH:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(611);
                        _la = _input.LA(1);
                        if (!(_la == MINUS || _la == SLASH)) {
                            _errHandler.recoverInline(this);
                        } else {
                            if (_input.LA(1) == Token.EOF) {
                                matchedEOF = true;
                            }
                            _errHandler.reportMatch(this);
                            consume();
                        }
                    }
                    break;
                default:
                    throw new NoViableAltException(this);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Multi_opContext extends ParserRuleContext {

        public Multi_opContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_multi_op;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMulti_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMulti_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMulti_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Multi_opContext multi_op() throws RecognitionException {
        Multi_opContext _localctx = new Multi_opContext(_ctx, getState());
        enterRule(_localctx, 80, RULE_multi_op);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(614);
                _la = _input.LA(1);
                if (!(_la == PLUS || _la == STAR)) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Binary_compContext extends ParserRuleContext {

        public Binary_compContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_binary_comp;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterBinary_comp(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitBinary_comp(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitBinary_comp(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Binary_compContext binary_comp() throws RecognitionException {
        Binary_compContext _localctx = new Binary_compContext(_ctx, getState());
        enterRule(_localctx, 82, RULE_binary_comp);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(616);
                _la = _input.LA(1);
                if (!(((((_la - 91)) & ~0x3f) == 0 && ((1L << (_la - 91)) & ((1L << (EQUAL - 91)) | (1L << (GT - 91)) | (1L << (LT - 91)) | (1L << (LTEQ - 91)) | (1L << (GTEQ - 91)))) != 0))) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class NameContext extends ParserRuleContext {

        public TerminalNode NAME() {
            return getToken(PDDLParser.NAME, 0);
        }

        public NameContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_name;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterName(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitName(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitName(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final NameContext name() throws RecognitionException {
        NameContext _localctx = new NameContext(_ctx, getState());
        enterRule(_localctx, 84, RULE_name);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(618);
                _la = _input.LA(1);
                if (!(((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0))) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class EffectContext extends ParserRuleContext {

        public EffectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_effect;
        }

        public EffectContext() {
        }

        public void copyFrom(EffectContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Effect_and_c_effectContext extends EffectContext {

        public List<C_effectContext> c_effect() {
            return getRuleContexts(C_effectContext.class);
        }

        public C_effectContext c_effect(int i) {
            return getRuleContext(C_effectContext.class, i);
        }

        public Effect_and_c_effectContext(EffectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterEffect_and_c_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitEffect_and_c_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitEffect_and_c_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Effect_c_effectContext extends EffectContext {

        public C_effectContext c_effect() {
            return getRuleContext(C_effectContext.class, 0);
        }

        public Effect_c_effectContext(EffectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterEffect_c_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitEffect_c_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitEffect_c_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final EffectContext effect() throws RecognitionException {
        EffectContext _localctx = new EffectContext(_ctx, getState());
        enterRule(_localctx, 86, RULE_effect);
        try {
            int _alt;
            setState(630);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 63, _ctx)) {
                case 1:
                    _localctx = new Effect_and_c_effectContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(620);
                        match(LPAREN);
                        setState(621);
                        match(AND);
                        setState(625);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 62, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(622);
                                        c_effect();
                                    }
                                }
                            }
                            setState(627);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 62, _ctx);
                        }
                        setState(628);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Effect_c_effectContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(629);
                        c_effect();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class C_effectContext extends ParserRuleContext {

        public C_effectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_c_effect;
        }

        public C_effectContext() {
        }

        public void copyFrom(C_effectContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class C_effect_whenContext extends C_effectContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Cond_effectContext cond_effect() {
            return getRuleContext(Cond_effectContext.class, 0);
        }

        public C_effect_whenContext(C_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterC_effect_when(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitC_effect_when(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitC_effect_when(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class C_effect_forallContext extends C_effectContext {

        public EffectContext effect() {
            return getRuleContext(EffectContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public C_effect_forallContext(C_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterC_effect_forall(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitC_effect_forall(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitC_effect_forall(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class C_effect_p_effectContext extends C_effectContext {

        public P_effectContext p_effect() {
            return getRuleContext(P_effectContext.class, 0);
        }

        public C_effect_p_effectContext(C_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterC_effect_p_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitC_effect_p_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitC_effect_p_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final C_effectContext c_effect() throws RecognitionException {
        C_effectContext _localctx = new C_effectContext(_ctx, getState());
        enterRule(_localctx, 88, RULE_c_effect);
        try {
            setState(651);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 65, _ctx)) {
                case 1:
                    _localctx = new C_effect_forallContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(632);
                        if (!(requirements.contains(":conditional-effects"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":conditional-effects\")");
                        }
                        setState(633);
                        match(LPAREN);
                        setState(634);
                        match(FORALL);
                        setState(635);
                        match(LPAREN);
                        setState(637);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 64, _ctx)) {
                            case 1: {
                                setState(636);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(639);
                        match(RPAREN);
                        setState(640);
                        effect();
                        setState(641);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new C_effect_whenContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(643);
                        if (!(requirements.contains(":conditional-effects"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":conditional-effects\")");
                        }
                        setState(644);
                        match(LPAREN);
                        setState(645);
                        match(WHEN);
                        setState(646);
                        gD();
                        setState(647);
                        cond_effect();
                        setState(648);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new C_effect_p_effectContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(650);
                        p_effect();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class P_effectContext extends ParserRuleContext {

        public P_effectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_p_effect;
        }

        public P_effectContext() {
        }

        public void copyFrom(P_effectContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class P_effect_directed_atomic_formula_termContext extends P_effectContext {

        public Atomic_formula_termContext atomic_formula_term() {
            return getRuleContext(Atomic_formula_termContext.class, 0);
        }

        public P_effect_directed_atomic_formula_termContext(P_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterP_effect_directed_atomic_formula_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitP_effect_directed_atomic_formula_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitP_effect_directed_atomic_formula_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class P_effect_negated_atomic_formula_termContext extends P_effectContext {

        public Atomic_formula_termContext atomic_formula_term() {
            return getRuleContext(Atomic_formula_termContext.class, 0);
        }

        public P_effect_negated_atomic_formula_termContext(P_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterP_effect_negated_atomic_formula_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitP_effect_negated_atomic_formula_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitP_effect_negated_atomic_formula_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class P_effect_assign_termContext extends P_effectContext {

        public Function_termContext function_term() {
            return getRuleContext(Function_termContext.class, 0);
        }

        public TermContext term() {
            return getRuleContext(TermContext.class, 0);
        }

        public P_effect_assign_termContext(P_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterP_effect_assign_term(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitP_effect_assign_term(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitP_effect_assign_term(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class P_effect_assign_undefinedContext extends P_effectContext {

        public Function_termContext function_term() {
            return getRuleContext(Function_termContext.class, 0);
        }

        public P_effect_assign_undefinedContext(P_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterP_effect_assign_undefined(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitP_effect_assign_undefined(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitP_effect_assign_undefined(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class P_effect_assign_op_f_head_f_expContext extends P_effectContext {

        public Assign_opContext assign_op() {
            return getRuleContext(Assign_opContext.class, 0);
        }

        public F_headContext f_head() {
            return getRuleContext(F_headContext.class, 0);
        }

        public F_expContext f_exp() {
            return getRuleContext(F_expContext.class, 0);
        }

        public P_effect_assign_op_f_head_f_expContext(P_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterP_effect_assign_op_f_head_f_exp(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitP_effect_assign_op_f_head_f_exp(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitP_effect_assign_op_f_head_f_exp(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final P_effectContext p_effect() throws RecognitionException {
        P_effectContext _localctx = new P_effectContext(_ctx, getState());
        enterRule(_localctx, 90, RULE_p_effect);
        try {
            setState(680);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 66, _ctx)) {
                case 1:
                    _localctx = new P_effect_negated_atomic_formula_termContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(653);
                        match(LPAREN);
                        setState(654);
                        match(NOT);
                        setState(655);
                        atomic_formula_term();
                        setState(656);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new P_effect_directed_atomic_formula_termContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(658);
                        atomic_formula_term();
                    }
                    break;
                case 3:
                    _localctx = new P_effect_assign_op_f_head_f_expContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(659);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(660);
                        match(LPAREN);
                        setState(661);
                        assign_op();
                        setState(662);
                        f_head();
                        setState(663);
                        f_exp();
                        setState(664);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new P_effect_assign_termContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(666);
                        if (!(requirements.contains(":object-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":object-fluents\")");
                        }
                        setState(667);
                        match(LPAREN);
                        setState(668);
                        match(ASSIGN);
                        setState(669);
                        function_term();
                        setState(670);
                        term();
                        setState(671);
                        match(RPAREN);
                    }
                    break;
                case 5:
                    _localctx = new P_effect_assign_undefinedContext(_localctx);
                    enterOuterAlt(_localctx, 5);
                     {
                        setState(673);
                        if (!(requirements.contains(":object-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":object-fluents\")");
                        }
                        setState(674);
                        match(LPAREN);
                        setState(675);
                        match(ASSIGN);
                        setState(676);
                        function_term();
                        setState(677);
                        match(UNDEFINED);
                        setState(678);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Cond_effectContext extends ParserRuleContext {

        public Cond_effectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_cond_effect;
        }

        public Cond_effectContext() {
        }

        public void copyFrom(Cond_effectContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Cond_effect_p_effectContext extends Cond_effectContext {

        public P_effectContext p_effect() {
            return getRuleContext(P_effectContext.class, 0);
        }

        public Cond_effect_p_effectContext(Cond_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCond_effect_p_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCond_effect_p_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCond_effect_p_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Cond_effect_and_p_effectContext extends Cond_effectContext {

        public List<P_effectContext> p_effect() {
            return getRuleContexts(P_effectContext.class);
        }

        public P_effectContext p_effect(int i) {
            return getRuleContext(P_effectContext.class, i);
        }

        public Cond_effect_and_p_effectContext(Cond_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCond_effect_and_p_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCond_effect_and_p_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCond_effect_and_p_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Cond_effectContext cond_effect() throws RecognitionException {
        Cond_effectContext _localctx = new Cond_effectContext(_ctx, getState());
        enterRule(_localctx, 92, RULE_cond_effect);
        try {
            int _alt;
            setState(692);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 68, _ctx)) {
                case 1:
                    _localctx = new Cond_effect_and_p_effectContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(682);
                        match(LPAREN);
                        setState(683);
                        match(AND);
                        setState(687);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 67, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(684);
                                        p_effect();
                                    }
                                }
                            }
                            setState(689);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 67, _ctx);
                        }
                        setState(690);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Cond_effect_p_effectContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(691);
                        p_effect();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Assign_opContext extends ParserRuleContext {

        public Assign_opContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_assign_op;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAssign_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAssign_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAssign_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Assign_opContext assign_op() throws RecognitionException {
        Assign_opContext _localctx = new Assign_opContext(_ctx, getState());
        enterRule(_localctx, 94, RULE_assign_op);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(694);
                _la = _input.LA(1);
                if (!((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ASSIGN) | (1L << SCALE_UP) | (1L << SCALE_DOWN) | (1L << INCREASE) | (1L << DECREASE))) != 0))) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Durative_action_defContext extends ParserRuleContext {

        public Da_symbolContext da_symbol() {
            return getRuleContext(Da_symbolContext.class, 0);
        }

        public Da_def_bodyContext da_def_body() {
            return getRuleContext(Da_def_bodyContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Durative_action_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_durative_action_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDurative_action_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDurative_action_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDurative_action_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Durative_action_defContext durative_action_def() throws RecognitionException {
        Durative_action_defContext _localctx = new Durative_action_defContext(_ctx, getState());
        enterRule(_localctx, 96, RULE_durative_action_def);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(696);
                match(LPAREN);
                setState(697);
                match(DURATIVE_ACTION);
                setState(698);
                da_symbol();
                setState(699);
                match(PARAMETERS);
                setState(700);
                match(LPAREN);
                setState(702);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 69, _ctx)) {
                    case 1: {
                        setState(701);
                        typed_list_variable();
                    }
                    break;
                }
                setState(704);
                match(RPAREN);
                setState(705);
                da_def_body();
                setState(706);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Da_symbolContext extends ParserRuleContext {

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Da_symbolContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_da_symbol;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_symbol(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_symbol(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_symbol(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Da_symbolContext da_symbol() throws RecognitionException {
        Da_symbolContext _localctx = new Da_symbolContext(_ctx, getState());
        enterRule(_localctx, 98, RULE_da_symbol);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(708);
                name();
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Da_def_bodyContext extends ParserRuleContext {

        public Duration_constraintContext duration_constraint() {
            return getRuleContext(Duration_constraintContext.class, 0);
        }

        public EmptyOr_da_GDContext emptyOr_da_GD() {
            return getRuleContext(EmptyOr_da_GDContext.class, 0);
        }

        public EmptyOr_da_effectContext emptyOr_da_effect() {
            return getRuleContext(EmptyOr_da_effectContext.class, 0);
        }

        public Da_def_bodyContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_da_def_body;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_def_body(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_def_body(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_def_body(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Da_def_bodyContext da_def_body() throws RecognitionException {
        Da_def_bodyContext _localctx = new Da_def_bodyContext(_ctx, getState());
        enterRule(_localctx, 100, RULE_da_def_body);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(710);
                match(DURATION);
                setState(711);
                duration_constraint();
                setState(712);
                match(CONDITION);
                setState(713);
                emptyOr_da_GD();
                setState(714);
                match(EFFECT);
                setState(715);
                emptyOr_da_effect();
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Da_GDContext extends ParserRuleContext {

        public Da_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_da_GD;
        }

        public Da_GDContext() {
        }

        public void copyFrom(Da_GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Da_GD_andContext extends Da_GDContext {

        public List<Da_GDContext> da_GD() {
            return getRuleContexts(Da_GDContext.class);
        }

        public Da_GDContext da_GD(int i) {
            return getRuleContext(Da_GDContext.class, i);
        }

        public Da_GD_andContext(Da_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_GD_and(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_GD_and(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_GD_and(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Da_GD_pref_timed_GDContext extends Da_GDContext {

        public Pref_timed_GDContext pref_timed_GD() {
            return getRuleContext(Pref_timed_GDContext.class, 0);
        }

        public Da_GD_pref_timed_GDContext(Da_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_GD_pref_timed_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_GD_pref_timed_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_GD_pref_timed_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Da_GD_forallContext extends Da_GDContext {

        public Da_GDContext da_GD() {
            return getRuleContext(Da_GDContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Da_GD_forallContext(Da_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_GD_forall(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_GD_forall(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_GD_forall(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Da_GDContext da_GD() throws RecognitionException {
        Da_GDContext _localctx = new Da_GDContext(_ctx, getState());
        enterRule(_localctx, 102, RULE_da_GD);
        try {
            int _alt;
            setState(738);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 72, _ctx)) {
                case 1:
                    _localctx = new Da_GD_pref_timed_GDContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(717);
                        pref_timed_GD();
                    }
                    break;
                case 2:
                    _localctx = new Da_GD_andContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(718);
                        match(LPAREN);
                        setState(719);
                        match(AND);
                        setState(723);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 70, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(720);
                                        da_GD();
                                    }
                                }
                            }
                            setState(725);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 70, _ctx);
                        }
                        setState(726);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Da_GD_forallContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(727);
                        if (!(requirements.contains(":universal-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":universal-preconditions\")");
                        }
                        setState(728);
                        match(LPAREN);
                        setState(729);
                        match(FORALL);
                        setState(730);
                        match(LPAREN);
                        setState(732);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 71, _ctx)) {
                            case 1: {
                                setState(731);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(734);
                        match(RPAREN);
                        setState(735);
                        da_GD();
                        setState(736);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Pref_timed_GDContext extends ParserRuleContext {

        public Pref_timed_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_pref_timed_GD;
        }

        public Pref_timed_GDContext() {
        }

        public void copyFrom(Pref_timed_GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Pref_timed_GD_timed_GDContext extends Pref_timed_GDContext {

        public Timed_GDContext timed_GD() {
            return getRuleContext(Timed_GDContext.class, 0);
        }

        public Pref_timed_GD_timed_GDContext(Pref_timed_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_timed_GD_timed_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_timed_GD_timed_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_timed_GD_timed_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Pref_timed_GD_preference_timed_GDContext extends Pref_timed_GDContext {

        public Timed_GDContext timed_GD() {
            return getRuleContext(Timed_GDContext.class, 0);
        }

        public Pref_nameContext pref_name() {
            return getRuleContext(Pref_nameContext.class, 0);
        }

        public Pref_timed_GD_preference_timed_GDContext(Pref_timed_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_timed_GD_preference_timed_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_timed_GD_preference_timed_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_timed_GD_preference_timed_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Pref_timed_GDContext pref_timed_GD() throws RecognitionException {
        Pref_timed_GDContext _localctx = new Pref_timed_GDContext(_ctx, getState());
        enterRule(_localctx, 104, RULE_pref_timed_GD);
        int _la;
        try {
            setState(750);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 74, _ctx)) {
                case 1:
                    _localctx = new Pref_timed_GD_timed_GDContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(740);
                        timed_GD();
                    }
                    break;
                case 2:
                    _localctx = new Pref_timed_GD_preference_timed_GDContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(741);
                        if (!(requirements.contains(":preferences"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":preferences\")");
                        }
                        setState(742);
                        match(LPAREN);
                        setState(743);
                        match(PREFERENCE);
                        setState(745);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        if (((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0)) {
                            {
                                setState(744);
                                pref_name();
                            }
                        }

                        setState(747);
                        timed_GD();
                        setState(748);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Timed_GDContext extends ParserRuleContext {

        public Timed_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_timed_GD;
        }

        public Timed_GDContext() {
        }

        public void copyFrom(Timed_GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Timed_GD_over_GDContext extends Timed_GDContext {

        public IntervalContext interval() {
            return getRuleContext(IntervalContext.class, 0);
        }

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Timed_GD_over_GDContext(Timed_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTimed_GD_over_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTimed_GD_over_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTimed_GD_over_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Timed_GD_at_GDContext extends Timed_GDContext {

        public Time_specifierContext time_specifier() {
            return getRuleContext(Time_specifierContext.class, 0);
        }

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Timed_GD_at_GDContext(Timed_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTimed_GD_at_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTimed_GD_at_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTimed_GD_at_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Timed_GDContext timed_GD() throws RecognitionException {
        Timed_GDContext _localctx = new Timed_GDContext(_ctx, getState());
        enterRule(_localctx, 106, RULE_timed_GD);
        try {
            setState(764);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 75, _ctx)) {
                case 1:
                    _localctx = new Timed_GD_at_GDContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(752);
                        match(LPAREN);
                        setState(753);
                        match(AT);
                        setState(754);
                        time_specifier();
                        setState(755);
                        gD();
                        setState(756);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Timed_GD_over_GDContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(758);
                        match(LPAREN);
                        setState(759);
                        match(OVER);
                        setState(760);
                        interval();
                        setState(761);
                        gD();
                        setState(762);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Time_specifierContext extends ParserRuleContext {

        public Time_specifierContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_time_specifier;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTime_specifier(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTime_specifier(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTime_specifier(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Time_specifierContext time_specifier() throws RecognitionException {
        Time_specifierContext _localctx = new Time_specifierContext(_ctx, getState());
        enterRule(_localctx, 108, RULE_time_specifier);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(766);
                _la = _input.LA(1);
                if (!(_la == START || _la == END)) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class IntervalContext extends ParserRuleContext {

        public IntervalContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_interval;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterInterval(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitInterval(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitInterval(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final IntervalContext interval() throws RecognitionException {
        IntervalContext _localctx = new IntervalContext(_ctx, getState());
        enterRule(_localctx, 110, RULE_interval);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(768);
                match(ALL);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Duration_constraintContext extends ParserRuleContext {

        public Duration_constraintContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_duration_constraint;
        }

        public Duration_constraintContext() {
        }

        public void copyFrom(Duration_constraintContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Duration_constraint_duration_constraintContext extends Duration_constraintContext {

        public Simple_duration_constraintContext simple_duration_constraint() {
            return getRuleContext(Simple_duration_constraintContext.class, 0);
        }

        public Duration_constraint_duration_constraintContext(Duration_constraintContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDuration_constraint_duration_constraint(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDuration_constraint_duration_constraint(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDuration_constraint_duration_constraint(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Duration_constraint_andContext extends Duration_constraintContext {

        public List<Simple_duration_constraintContext> simple_duration_constraint() {
            return getRuleContexts(Simple_duration_constraintContext.class);
        }

        public Simple_duration_constraintContext simple_duration_constraint(int i) {
            return getRuleContext(Simple_duration_constraintContext.class, i);
        }

        public Duration_constraint_andContext(Duration_constraintContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDuration_constraint_and(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDuration_constraint_and(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDuration_constraint_and(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Duration_constraint_emptyContext extends Duration_constraintContext {

        public Duration_constraint_emptyContext(Duration_constraintContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDuration_constraint_empty(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDuration_constraint_empty(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDuration_constraint_empty(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Duration_constraintContext duration_constraint() throws RecognitionException {
        Duration_constraintContext _localctx = new Duration_constraintContext(_ctx, getState());
        enterRule(_localctx, 112, RULE_duration_constraint);
        int _la;
        try {
            setState(783);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 77, _ctx)) {
                case 1:
                    _localctx = new Duration_constraint_andContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(770);
                        if (!(requirements.contains(":duration-inequalities"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":duration-inequalities\")");
                        }
                        setState(771);
                        match(LPAREN);
                        setState(772);
                        match(AND);
                        setState(774);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        do {
                            {
                                {
                                    setState(773);
                                    simple_duration_constraint();
                                }
                            }
                            setState(776);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        } while (_la == LPAREN);
                        setState(778);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Duration_constraint_emptyContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(780);
                        match(LPAREN);
                        setState(781);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Duration_constraint_duration_constraintContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(782);
                        simple_duration_constraint();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Simple_duration_constraintContext extends ParserRuleContext {

        public Simple_duration_constraintContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_simple_duration_constraint;
        }

        public Simple_duration_constraintContext() {
        }

        public void copyFrom(Simple_duration_constraintContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Simple_duration_constraint_atContext extends Simple_duration_constraintContext {

        public Time_specifierContext time_specifier() {
            return getRuleContext(Time_specifierContext.class, 0);
        }

        public Simple_duration_constraintContext simple_duration_constraint() {
            return getRuleContext(Simple_duration_constraintContext.class, 0);
        }

        public Simple_duration_constraint_atContext(Simple_duration_constraintContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterSimple_duration_constraint_at(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitSimple_duration_constraint_at(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitSimple_duration_constraint_at(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Simple_duration_constraint_d_opContext extends Simple_duration_constraintContext {

        public D_opContext d_op() {
            return getRuleContext(D_opContext.class, 0);
        }

        public D_valueContext d_value() {
            return getRuleContext(D_valueContext.class, 0);
        }

        public Simple_duration_constraint_d_opContext(Simple_duration_constraintContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterSimple_duration_constraint_d_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitSimple_duration_constraint_d_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitSimple_duration_constraint_d_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Simple_duration_constraintContext simple_duration_constraint() throws RecognitionException {
        Simple_duration_constraintContext _localctx = new Simple_duration_constraintContext(_ctx, getState());
        enterRule(_localctx, 114, RULE_simple_duration_constraint);
        try {
            setState(797);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 78, _ctx)) {
                case 1:
                    _localctx = new Simple_duration_constraint_d_opContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(785);
                        match(LPAREN);
                        setState(786);
                        d_op();
                        setState(787);
                        match(DURATION_VARIABLE);
                        setState(788);
                        d_value();
                        setState(789);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Simple_duration_constraint_atContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(791);
                        match(LPAREN);
                        setState(792);
                        match(AT);
                        setState(793);
                        time_specifier();
                        setState(794);
                        simple_duration_constraint();
                        setState(795);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class D_opContext extends ParserRuleContext {

        public D_opContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_d_op;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterD_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitD_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitD_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final D_opContext d_op() throws RecognitionException {
        D_opContext _localctx = new D_opContext(_ctx, getState());
        enterRule(_localctx, 116, RULE_d_op);
        try {
            setState(804);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 79, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(799);
                        if (!(requirements.contains(":duration-inequalities"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":duration-inequalities\")");
                        }
                        setState(800);
                        match(LTEQ);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(801);
                        if (!(requirements.contains(":duration-inequalities"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":duration-inequalities\")");
                        }
                        setState(802);
                        match(GTEQ);
                    }
                    break;
                case 3:
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(803);
                        match(EQUAL);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class D_valueContext extends ParserRuleContext {

        public D_valueContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_d_value;
        }

        public D_valueContext() {
        }

        public void copyFrom(D_valueContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class D_value_f_expContext extends D_valueContext {

        public F_expContext f_exp() {
            return getRuleContext(F_expContext.class, 0);
        }

        public D_value_f_expContext(D_valueContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterD_value_f_exp(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitD_value_f_exp(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitD_value_f_exp(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class D_value_numberContext extends D_valueContext {

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public D_value_numberContext(D_valueContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterD_value_number(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitD_value_number(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitD_value_number(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final D_valueContext d_value() throws RecognitionException {
        D_valueContext _localctx = new D_valueContext(_ctx, getState());
        enterRule(_localctx, 118, RULE_d_value);
        try {
            setState(809);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 80, _ctx)) {
                case 1:
                    _localctx = new D_value_numberContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(806);
                        match(NUMBER);
                    }
                    break;
                case 2:
                    _localctx = new D_value_f_expContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(807);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(808);
                        f_exp();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Da_effectContext extends ParserRuleContext {

        public Da_effectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_da_effect;
        }

        public Da_effectContext() {
        }

        public void copyFrom(Da_effectContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Da_effect_forallContext extends Da_effectContext {

        public Da_effectContext da_effect() {
            return getRuleContext(Da_effectContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Da_effect_forallContext(Da_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_effect_forall(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_effect_forall(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_effect_forall(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Da_effect_whenContext extends Da_effectContext {

        public Da_GDContext da_GD() {
            return getRuleContext(Da_GDContext.class, 0);
        }

        public Timed_effectContext timed_effect() {
            return getRuleContext(Timed_effectContext.class, 0);
        }

        public Da_effect_whenContext(Da_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_effect_when(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_effect_when(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_effect_when(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Da_effect_andContext extends Da_effectContext {

        public List<Da_effectContext> da_effect() {
            return getRuleContexts(Da_effectContext.class);
        }

        public Da_effectContext da_effect(int i) {
            return getRuleContext(Da_effectContext.class, i);
        }

        public Da_effect_andContext(Da_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_effect_and(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_effect_and(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_effect_and(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Da_effect_timed_effectContext extends Da_effectContext {

        public Timed_effectContext timed_effect() {
            return getRuleContext(Timed_effectContext.class, 0);
        }

        public Da_effect_timed_effectContext(Da_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDa_effect_timed_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDa_effect_timed_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDa_effect_timed_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Da_effectContext da_effect() throws RecognitionException {
        Da_effectContext _localctx = new Da_effectContext(_ctx, getState());
        enterRule(_localctx, 120, RULE_da_effect);
        try {
            int _alt;
            setState(839);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 83, _ctx)) {
                case 1:
                    _localctx = new Da_effect_andContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(811);
                        match(LPAREN);
                        setState(812);
                        match(AND);
                        setState(816);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 81, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(813);
                                        da_effect();
                                    }
                                }
                            }
                            setState(818);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 81, _ctx);
                        }
                        setState(819);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Da_effect_timed_effectContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(820);
                        timed_effect();
                    }
                    break;
                case 3:
                    _localctx = new Da_effect_forallContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(821);
                        if (!(requirements.contains(":conditional-effects"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":conditional-effects\")");
                        }
                        setState(822);
                        match(LPAREN);
                        setState(823);
                        match(FORALL);
                        setState(824);
                        match(LPAREN);
                        setState(826);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 82, _ctx)) {
                            case 1: {
                                setState(825);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(828);
                        match(RPAREN);
                        setState(829);
                        da_effect();
                        setState(830);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new Da_effect_whenContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(832);
                        if (!(requirements.contains(":conditional-effects"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":conditional-effects\")");
                        }
                        setState(833);
                        match(LPAREN);
                        setState(834);
                        match(WHEN);
                        setState(835);
                        da_GD();
                        setState(836);
                        timed_effect();
                        setState(837);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Timed_effectContext extends ParserRuleContext {

        public Timed_effectContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_timed_effect;
        }

        public Timed_effectContext() {
        }

        public void copyFrom(Timed_effectContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Timed_effect_cond_effectContext extends Timed_effectContext {

        public Time_specifierContext time_specifier() {
            return getRuleContext(Time_specifierContext.class, 0);
        }

        public Cond_effectContext cond_effect() {
            return getRuleContext(Cond_effectContext.class, 0);
        }

        public Timed_effect_cond_effectContext(Timed_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTimed_effect_cond_effect(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTimed_effect_cond_effect(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTimed_effect_cond_effect(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Timed_effect_assign_opContext extends Timed_effectContext {

        public Assign_op_tContext assign_op_t() {
            return getRuleContext(Assign_op_tContext.class, 0);
        }

        public F_headContext f_head() {
            return getRuleContext(F_headContext.class, 0);
        }

        public F_exp_tContext f_exp_t() {
            return getRuleContext(F_exp_tContext.class, 0);
        }

        public Timed_effect_assign_opContext(Timed_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTimed_effect_assign_op(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTimed_effect_assign_op(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTimed_effect_assign_op(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Timed_effect_f_assign_daContext extends Timed_effectContext {

        public Time_specifierContext time_specifier() {
            return getRuleContext(Time_specifierContext.class, 0);
        }

        public F_assign_daContext f_assign_da() {
            return getRuleContext(F_assign_daContext.class, 0);
        }

        public Timed_effect_f_assign_daContext(Timed_effectContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterTimed_effect_f_assign_da(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitTimed_effect_f_assign_da(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitTimed_effect_f_assign_da(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Timed_effectContext timed_effect() throws RecognitionException {
        Timed_effectContext _localctx = new Timed_effectContext(_ctx, getState());
        enterRule(_localctx, 122, RULE_timed_effect);
        try {
            setState(861);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 84, _ctx)) {
                case 1:
                    _localctx = new Timed_effect_cond_effectContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(841);
                        match(LPAREN);
                        setState(842);
                        match(AT);
                        setState(843);
                        time_specifier();
                        setState(844);
                        cond_effect();
                        setState(845);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Timed_effect_f_assign_daContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(847);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(848);
                        match(LPAREN);
                        setState(849);
                        match(AT);
                        setState(850);
                        time_specifier();
                        setState(851);
                        f_assign_da();
                        setState(852);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Timed_effect_assign_opContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(854);
                        if (!(requirements.contains(":continuous-effects") && requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":continuous-effects\") && requirements.contains(\":numeric-fluents\")");
                        }
                        setState(855);
                        match(LPAREN);
                        setState(856);
                        assign_op_t();
                        setState(857);
                        f_head();
                        setState(858);
                        f_exp_t();
                        setState(859);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class F_assign_daContext extends ParserRuleContext {

        public Assign_opContext assign_op() {
            return getRuleContext(Assign_opContext.class, 0);
        }

        public F_headContext f_head() {
            return getRuleContext(F_headContext.class, 0);
        }

        public F_exp_daContext f_exp_da() {
            return getRuleContext(F_exp_daContext.class, 0);
        }

        public F_assign_daContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_f_assign_da;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_assign_da(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_assign_da(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_assign_da(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final F_assign_daContext f_assign_da() throws RecognitionException {
        F_assign_daContext _localctx = new F_assign_daContext(_ctx, getState());
        enterRule(_localctx, 124, RULE_f_assign_da);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(863);
                match(LPAREN);
                setState(864);
                assign_op();
                setState(865);
                f_head();
                setState(866);
                f_exp_da();
                setState(867);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class F_exp_daContext extends ParserRuleContext {

        public F_exp_daContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_f_exp_da;
        }

        public F_exp_daContext() {
        }

        public void copyFrom(F_exp_daContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class F_exp_da_multiContext extends F_exp_daContext {

        public Multi_opContext multi_op() {
            return getRuleContext(Multi_opContext.class, 0);
        }

        public List<F_exp_daContext> f_exp_da() {
            return getRuleContexts(F_exp_daContext.class);
        }

        public F_exp_daContext f_exp_da(int i) {
            return getRuleContext(F_exp_daContext.class, i);
        }

        public F_exp_da_multiContext(F_exp_daContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_da_multi(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_da_multi(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_da_multi(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_da_durationContext extends F_exp_daContext {

        public F_exp_da_durationContext(F_exp_daContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_da_duration(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_da_duration(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_da_duration(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_da_minusContext extends F_exp_daContext {

        public F_exp_daContext f_exp_da() {
            return getRuleContext(F_exp_daContext.class, 0);
        }

        public F_exp_da_minusContext(F_exp_daContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_da_minus(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_da_minus(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_da_minus(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_da_binaryContext extends F_exp_daContext {

        public Binary_opContext binary_op() {
            return getRuleContext(Binary_opContext.class, 0);
        }

        public List<F_exp_daContext> f_exp_da() {
            return getRuleContexts(F_exp_daContext.class);
        }

        public F_exp_daContext f_exp_da(int i) {
            return getRuleContext(F_exp_daContext.class, i);
        }

        public F_exp_da_binaryContext(F_exp_daContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_da_binary(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_da_binary(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_da_binary(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class F_exp_da_f_expContext extends F_exp_daContext {

        public F_expContext f_exp() {
            return getRuleContext(F_expContext.class, 0);
        }

        public F_exp_da_f_expContext(F_exp_daContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_da_f_exp(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_da_f_exp(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_da_f_exp(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final F_exp_daContext f_exp_da() throws RecognitionException {
        F_exp_daContext _localctx = new F_exp_daContext(_ctx, getState());
        enterRule(_localctx, 126, RULE_f_exp_da);
        try {
            int _alt;
            setState(893);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 86, _ctx)) {
                case 1:
                    _localctx = new F_exp_da_binaryContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(869);
                        match(LPAREN);
                        setState(870);
                        binary_op();
                        setState(871);
                        f_exp_da();
                        setState(872);
                        f_exp_da();
                        setState(873);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new F_exp_da_multiContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(875);
                        match(LPAREN);
                        setState(876);
                        multi_op();
                        setState(877);
                        f_exp_da();
                        setState(879);
                        _errHandler.sync(this);
                        _alt = 1;
                        do {
                            switch (_alt) {
                                case 1: {
                                    {
                                        setState(878);
                                        f_exp_da();
                                    }
                                }
                                break;
                                default:
                                    throw new NoViableAltException(this);
                            }
                            setState(881);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 85, _ctx);
                        } while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER);
                        setState(883);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new F_exp_da_minusContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(885);
                        match(LPAREN);
                        setState(886);
                        match(MINUS);
                        setState(887);
                        f_exp_da();
                        setState(888);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new F_exp_da_durationContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(890);
                        if (!(requirements.contains(":duration-inequalities"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":duration-inequalities\")");
                        }
                        setState(891);
                        match(DURATION_VARIABLE);
                    }
                    break;
                case 5:
                    _localctx = new F_exp_da_f_expContext(_localctx);
                    enterOuterAlt(_localctx, 5);
                     {
                        setState(892);
                        f_exp();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Assign_op_tContext extends ParserRuleContext {

        public Assign_op_tContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_assign_op_t;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterAssign_op_t(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitAssign_op_t(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitAssign_op_t(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Assign_op_tContext assign_op_t() throws RecognitionException {
        Assign_op_tContext _localctx = new Assign_op_tContext(_ctx, getState());
        enterRule(_localctx, 128, RULE_assign_op_t);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(895);
                _la = _input.LA(1);
                if (!(_la == INCREASE || _la == DECREASE)) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class F_exp_tContext extends ParserRuleContext {

        public F_expContext f_exp() {
            return getRuleContext(F_expContext.class, 0);
        }

        public F_exp_tContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_f_exp_t;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterF_exp_t(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitF_exp_t(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitF_exp_t(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final F_exp_tContext f_exp_t() throws RecognitionException {
        F_exp_tContext _localctx = new F_exp_tContext(_ctx, getState());
        enterRule(_localctx, 130, RULE_f_exp_t);
        try {
            setState(910);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 87, _ctx)) {
                case 1:
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(897);
                        match(LPAREN);
                        setState(898);
                        match(STAR);
                        setState(899);
                        f_exp();
                        setState(900);
                        match(TIME);
                        setState(901);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(903);
                        match(LPAREN);
                        setState(904);
                        match(STAR);
                        setState(905);
                        match(TIME);
                        setState(906);
                        f_exp();
                        setState(907);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(909);
                        match(TIME);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Derived_defContext extends ParserRuleContext {

        public Atomic_formula_skeletonContext atomic_formula_skeleton() {
            return getRuleContext(Atomic_formula_skeletonContext.class, 0);
        }

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Derived_defContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_derived_def;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterDerived_def(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitDerived_def(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitDerived_def(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Derived_defContext derived_def() throws RecognitionException {
        Derived_defContext _localctx = new Derived_defContext(_ctx, getState());
        enterRule(_localctx, 132, RULE_derived_def);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(912);
                match(LPAREN);
                setState(913);
                match(DERIVED);
                setState(914);
                atomic_formula_skeleton();
                setState(915);
                gD();
                setState(916);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class ProblemContext extends ParserRuleContext {

        public List<NameContext> name() {
            return getRuleContexts(NameContext.class);
        }

        public NameContext name(int i) {
            return getRuleContext(NameContext.class, i);
        }

        public InitContext init() {
            return getRuleContext(InitContext.class, 0);
        }

        public GoalContext goal() {
            return getRuleContext(GoalContext.class, 0);
        }

        public Require_defContext require_def() {
            return getRuleContext(Require_defContext.class, 0);
        }

        public Object_declarationContext object_declaration() {
            return getRuleContext(Object_declarationContext.class, 0);
        }

        public ConstraintsContext constraints() {
            return getRuleContext(ConstraintsContext.class, 0);
        }

        public Metric_specContext metric_spec() {
            return getRuleContext(Metric_specContext.class, 0);
        }

        public Length_specContext length_spec() {
            return getRuleContext(Length_specContext.class, 0);
        }

        public ProblemContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_problem;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterProblem(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitProblem(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitProblem(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final ProblemContext problem() throws RecognitionException {
        ProblemContext _localctx = new ProblemContext(_ctx, getState());
        enterRule(_localctx, 134, RULE_problem);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(918);
                match(LPAREN);
                setState(919);
                match(DEFINE);
                setState(920);
                match(LPAREN);
                setState(921);
                match(PROBLEM);
                setState(922);
                name();
                setState(923);
                match(RPAREN);
                setState(924);
                match(LPAREN);
                setState(925);
                match(PROBLEM_DOMAIN);
                setState(926);
                name();
                setState(927);
                match(RPAREN);
                setState(929);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 88, _ctx)) {
                    case 1: {
                        setState(928);
                        require_def();
                    }
                    break;
                }
                setState(932);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 89, _ctx)) {
                    case 1: {
                        setState(931);
                        object_declaration();
                    }
                    break;
                }
                setState(934);
                init();
                setState(935);
                goal();
                setState(937);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 90, _ctx)) {
                    case 1: {
                        setState(936);
                        constraints();
                    }
                    break;
                }
                setState(940);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 91, _ctx)) {
                    case 1: {
                        setState(939);
                        metric_spec();
                    }
                    break;
                }
                setState(943);
                _errHandler.sync(this);
                _la = _input.LA(1);
                if (_la == LPAREN) {
                    {
                        setState(942);
                        length_spec();
                    }
                }

                setState(945);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Object_declarationContext extends ParserRuleContext {

        public Typed_list_nameContext typed_list_name() {
            return getRuleContext(Typed_list_nameContext.class, 0);
        }

        public Object_declarationContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_object_declaration;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterObject_declaration(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitObject_declaration(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitObject_declaration(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Object_declarationContext object_declaration() throws RecognitionException {
        Object_declarationContext _localctx = new Object_declarationContext(_ctx, getState());
        enterRule(_localctx, 136, RULE_object_declaration);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(947);
                match(LPAREN);
                setState(948);
                match(OBJECTS);
                setState(950);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 93, _ctx)) {
                    case 1: {
                        setState(949);
                        typed_list_name();
                    }
                    break;
                }
                setState(952);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class InitContext extends ParserRuleContext {

        public List<Init_elContext> init_el() {
            return getRuleContexts(Init_elContext.class);
        }

        public Init_elContext init_el(int i) {
            return getRuleContext(Init_elContext.class, i);
        }

        public InitContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_init;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterInit(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitInit(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitInit(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final InitContext init() throws RecognitionException {
        InitContext _localctx = new InitContext(_ctx, getState());
        enterRule(_localctx, 138, RULE_init);
        try {
            int _alt;
            enterOuterAlt(_localctx, 1);
            {
                setState(954);
                match(LPAREN);
                setState(955);
                match(INIT);
                setState(959);
                _errHandler.sync(this);
                _alt = getInterpreter().adaptivePredict(_input, 94, _ctx);
                while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                    if (_alt == 1) {
                        {
                            {
                                setState(956);
                                init_el();
                            }
                        }
                    }
                    setState(961);
                    _errHandler.sync(this);
                    _alt = getInterpreter().adaptivePredict(_input, 94, _ctx);
                }
                setState(962);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Init_elContext extends ParserRuleContext {

        public Init_elContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_init_el;
        }

        public Init_elContext() {
        }

        public void copyFrom(Init_elContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Init_el_eq_nameContext extends Init_elContext {

        public Basic_function_termContext basic_function_term() {
            return getRuleContext(Basic_function_termContext.class, 0);
        }

        public NameContext name() {
            return getRuleContext(NameContext.class, 0);
        }

        public Init_el_eq_nameContext(Init_elContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterInit_el_eq_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitInit_el_eq_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitInit_el_eq_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Init_el_eq_numberContext extends Init_elContext {

        public Basic_function_termContext basic_function_term() {
            return getRuleContext(Basic_function_termContext.class, 0);
        }

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public Init_el_eq_numberContext(Init_elContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterInit_el_eq_number(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitInit_el_eq_number(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitInit_el_eq_number(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Init_el_literal_nameContext extends Init_elContext {

        public Literal_nameContext literal_name() {
            return getRuleContext(Literal_nameContext.class, 0);
        }

        public Init_el_literal_nameContext(Init_elContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterInit_el_literal_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitInit_el_literal_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitInit_el_literal_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Init_el_atContext extends Init_elContext {

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public Literal_nameContext literal_name() {
            return getRuleContext(Literal_nameContext.class, 0);
        }

        public Init_el_atContext(Init_elContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterInit_el_at(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitInit_el_at(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitInit_el_at(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Init_elContext init_el() throws RecognitionException {
        Init_elContext _localctx = new Init_elContext(_ctx, getState());
        enterRule(_localctx, 140, RULE_init_el);
        try {
            setState(986);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 95, _ctx)) {
                case 1:
                    _localctx = new Init_el_literal_nameContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(964);
                        literal_name();
                    }
                    break;
                case 2:
                    _localctx = new Init_el_atContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(965);
                        if (!(requirements.contains(":timed-initial-literals"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":timed-initial-literals\")");
                        }
                        setState(966);
                        match(LPAREN);
                        setState(967);
                        match(AT);
                        setState(968);
                        match(NUMBER);
                        setState(969);
                        literal_name();
                        setState(970);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Init_el_eq_numberContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(972);
                        if (!(requirements.contains(":numeric-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                        }
                        setState(973);
                        match(LPAREN);
                        setState(974);
                        match(EQUAL);
                        setState(975);
                        basic_function_term();
                        setState(976);
                        match(NUMBER);
                        setState(977);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new Init_el_eq_nameContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(979);
                        if (!(requirements.contains(":object-fluents"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":object-fluents\")");
                        }
                        setState(980);
                        match(LPAREN);
                        setState(981);
                        match(EQUAL);
                        setState(982);
                        basic_function_term();
                        setState(983);
                        name();
                        setState(984);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Basic_function_termContext extends ParserRuleContext {

        public Basic_function_termContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_basic_function_term;
        }

        public Basic_function_termContext() {
        }

        public void copyFrom(Basic_function_termContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Basic_function_term_function_symbolContext extends Basic_function_termContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public Basic_function_term_function_symbolContext(Basic_function_termContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterBasic_function_term_function_symbol(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitBasic_function_term_function_symbol(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitBasic_function_term_function_symbol(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Basic_function_term_function_symbol_namesContext extends Basic_function_termContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public List<NameContext> name() {
            return getRuleContexts(NameContext.class);
        }

        public NameContext name(int i) {
            return getRuleContext(NameContext.class, i);
        }

        public Basic_function_term_function_symbol_namesContext(Basic_function_termContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterBasic_function_term_function_symbol_names(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitBasic_function_term_function_symbol_names(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitBasic_function_term_function_symbol_names(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Basic_function_termContext basic_function_term() throws RecognitionException {
        Basic_function_termContext _localctx = new Basic_function_termContext(_ctx, getState());
        enterRule(_localctx, 142, RULE_basic_function_term);
        int _la;
        try {
            setState(999);
            _errHandler.sync(this);
            switch (_input.LA(1)) {
                case AT:
                case OVER:
                case NAME:
                    _localctx = new Basic_function_term_function_symbolContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(988);
                        function_symbol();
                    }
                    break;
                case LPAREN:
                    _localctx = new Basic_function_term_function_symbol_namesContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(989);
                        match(LPAREN);
                        setState(990);
                        function_symbol();
                        setState(994);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        while (((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0)) {
                            {
                                {
                                    setState(991);
                                    name();
                                }
                            }
                            setState(996);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        }
                        setState(997);
                        match(RPAREN);
                    }
                    break;
                default:
                    throw new NoViableAltException(this);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class GoalContext extends ParserRuleContext {

        public Pre_GDContext pre_GD() {
            return getRuleContext(Pre_GDContext.class, 0);
        }

        public GoalContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_goal;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterGoal(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitGoal(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitGoal(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final GoalContext goal() throws RecognitionException {
        GoalContext _localctx = new GoalContext(_ctx, getState());
        enterRule(_localctx, 144, RULE_goal);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(1_001);
                match(LPAREN);
                setState(1_002);
                match(GOAL);
                setState(1_003);
                pre_GD();
                setState(1_004);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Pref_con_GDContext extends ParserRuleContext {

        public Pref_con_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_pref_con_GD;
        }

        public Pref_con_GDContext() {
        }

        public void copyFrom(Pref_con_GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Pref_con_GD_forallContext extends Pref_con_GDContext {

        public Pref_con_GDContext pref_con_GD() {
            return getRuleContext(Pref_con_GDContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Pref_con_GD_forallContext(Pref_con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_con_GD_forall(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_con_GD_forall(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_con_GD_forall(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Pref_con_GD_preferenceContext extends Pref_con_GDContext {

        public Con_GDContext con_GD() {
            return getRuleContext(Con_GDContext.class, 0);
        }

        public Pref_nameContext pref_name() {
            return getRuleContext(Pref_nameContext.class, 0);
        }

        public Pref_con_GD_preferenceContext(Pref_con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_con_GD_preference(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_con_GD_preference(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_con_GD_preference(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Pref_con_GD_con_GDContext extends Pref_con_GDContext {

        public Con_GDContext con_GD() {
            return getRuleContext(Con_GDContext.class, 0);
        }

        public Pref_con_GD_con_GDContext(Pref_con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_con_GD_con_GD(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_con_GD_con_GD(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_con_GD_con_GD(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Pref_con_GD_andContext extends Pref_con_GDContext {

        public List<Pref_con_GDContext> pref_con_GD() {
            return getRuleContexts(Pref_con_GDContext.class);
        }

        public Pref_con_GDContext pref_con_GD(int i) {
            return getRuleContext(Pref_con_GDContext.class, i);
        }

        public Pref_con_GD_andContext(Pref_con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterPref_con_GD_and(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitPref_con_GD_and(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitPref_con_GD_and(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Pref_con_GDContext pref_con_GD() throws RecognitionException {
        Pref_con_GDContext _localctx = new Pref_con_GDContext(_ctx, getState());
        enterRule(_localctx, 146, RULE_pref_con_GD);
        int _la;
        try {
            int _alt;
            setState(1_036);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 101, _ctx)) {
                case 1:
                    _localctx = new Pref_con_GD_andContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(1_006);
                        match(LPAREN);
                        setState(1_007);
                        match(AND);
                        setState(1_011);
                        _errHandler.sync(this);
                        _alt = getInterpreter().adaptivePredict(_input, 98, _ctx);
                        while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER) {
                            if (_alt == 1) {
                                {
                                    {
                                        setState(1_008);
                                        pref_con_GD();
                                    }
                                }
                            }
                            setState(1_013);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 98, _ctx);
                        }
                        setState(1_014);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Pref_con_GD_forallContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(1_015);
                        if (!(requirements.contains(":universal-preconditions"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":universal-preconditions\")");
                        }
                        setState(1_016);
                        match(LPAREN);
                        setState(1_017);
                        match(FORALL);
                        setState(1_018);
                        match(LPAREN);
                        setState(1_020);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 99, _ctx)) {
                            case 1: {
                                setState(1_019);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(1_022);
                        match(RPAREN);
                        setState(1_023);
                        pref_con_GD();
                        setState(1_024);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Pref_con_GD_preferenceContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(1_026);
                        if (!(requirements.contains(":preferences"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":preferences\")");
                        }
                        setState(1_027);
                        match(LPAREN);
                        setState(1_028);
                        match(PREFERENCE);
                        setState(1_030);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        if (((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0)) {
                            {
                                setState(1_029);
                                pref_name();
                            }
                        }

                        setState(1_032);
                        con_GD();
                        setState(1_033);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new Pref_con_GD_con_GDContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(1_035);
                        con_GD();
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Con_GDContext extends ParserRuleContext {

        public Con_GDContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_con_GD;
        }

        public Con_GDContext() {
        }

        public void copyFrom(Con_GDContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Con_GD_withinContext extends Con_GDContext {

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Con_GD_withinContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_within(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_within(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_within(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_hold_duringContext extends Con_GDContext {

        public List<TerminalNode> NUMBER() {
            return getTokens(PDDLParser.NUMBER);
        }

        public TerminalNode NUMBER(int i) {
            return getToken(PDDLParser.NUMBER, i);
        }

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Con_GD_hold_duringContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_hold_during(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_hold_during(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_hold_during(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_andContext extends Con_GDContext {

        public List<Con_GDContext> con_GD() {
            return getRuleContexts(Con_GDContext.class);
        }

        public Con_GDContext con_GD(int i) {
            return getRuleContext(Con_GDContext.class, i);
        }

        public Con_GD_andContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_and(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_and(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_and(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_sometimeContext extends Con_GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Con_GD_sometimeContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_sometime(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_sometime(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_sometime(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_alwaysContext extends Con_GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Con_GD_alwaysContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_always(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_always(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_always(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_sometime_afterContext extends Con_GDContext {

        public List<GDContext> gD() {
            return getRuleContexts(GDContext.class);
        }

        public GDContext gD(int i) {
            return getRuleContext(GDContext.class, i);
        }

        public Con_GD_sometime_afterContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_sometime_after(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_sometime_after(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_sometime_after(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_always_withinContext extends Con_GDContext {

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public List<GDContext> gD() {
            return getRuleContexts(GDContext.class);
        }

        public GDContext gD(int i) {
            return getRuleContext(GDContext.class, i);
        }

        public Con_GD_always_withinContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_always_within(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_always_within(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_always_within(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_sometime_beforeContext extends Con_GDContext {

        public List<GDContext> gD() {
            return getRuleContexts(GDContext.class);
        }

        public GDContext gD(int i) {
            return getRuleContext(GDContext.class, i);
        }

        public Con_GD_sometime_beforeContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_sometime_before(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_sometime_before(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_sometime_before(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_at_endContext extends Con_GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Con_GD_at_endContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_at_end(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_at_end(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_at_end(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_at_most_onceContext extends Con_GDContext {

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Con_GD_at_most_onceContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_at_most_once(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_at_most_once(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_at_most_once(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_forallContext extends Con_GDContext {

        public Con_GDContext con_GD() {
            return getRuleContext(Con_GDContext.class, 0);
        }

        public Typed_list_variableContext typed_list_variable() {
            return getRuleContext(Typed_list_variableContext.class, 0);
        }

        public Con_GD_forallContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_forall(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_forall(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_forall(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Con_GD_hold_afterContext extends Con_GDContext {

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public GDContext gD() {
            return getRuleContext(GDContext.class, 0);
        }

        public Con_GD_hold_afterContext(Con_GDContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterCon_GD_hold_after(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitCon_GD_hold_after(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitCon_GD_hold_after(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Con_GDContext con_GD() throws RecognitionException {
        Con_GDContext _localctx = new Con_GDContext(_ctx, getState());
        enterRule(_localctx, 148, RULE_con_GD);
        int _la;
        try {
            setState(1_116);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 104, _ctx)) {
                case 1:
                    _localctx = new Con_GD_andContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(1_038);
                        match(LPAREN);
                        setState(1_039);
                        match(AND);
                        setState(1_043);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        while (_la == LPAREN) {
                            {
                                {
                                    setState(1_040);
                                    con_GD();
                                }
                            }
                            setState(1_045);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        }
                        setState(1_046);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Con_GD_forallContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(1_047);
                        match(LPAREN);
                        setState(1_048);
                        match(FORALL);
                        setState(1_049);
                        match(LPAREN);
                        setState(1_051);
                        _errHandler.sync(this);
                        switch (getInterpreter().adaptivePredict(_input, 103, _ctx)) {
                            case 1: {
                                setState(1_050);
                                typed_list_variable();
                            }
                            break;
                        }
                        setState(1_053);
                        match(RPAREN);
                        setState(1_054);
                        con_GD();
                        setState(1_055);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Con_GD_at_endContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(1_057);
                        match(LPAREN);
                        setState(1_058);
                        match(AT);
                        setState(1_059);
                        match(END);
                        setState(1_060);
                        gD();
                        setState(1_061);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new Con_GD_alwaysContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(1_063);
                        match(LPAREN);
                        setState(1_064);
                        match(ALWAYS);
                        setState(1_065);
                        gD();
                        setState(1_066);
                        match(RPAREN);
                    }
                    break;
                case 5:
                    _localctx = new Con_GD_sometimeContext(_localctx);
                    enterOuterAlt(_localctx, 5);
                     {
                        setState(1_068);
                        match(LPAREN);
                        setState(1_069);
                        match(SOMETIME);
                        setState(1_070);
                        gD();
                        setState(1_071);
                        match(RPAREN);
                    }
                    break;
                case 6:
                    _localctx = new Con_GD_withinContext(_localctx);
                    enterOuterAlt(_localctx, 6);
                     {
                        setState(1_073);
                        match(LPAREN);
                        setState(1_074);
                        match(WITHIN);
                        setState(1_075);
                        match(NUMBER);
                        setState(1_076);
                        gD();
                        setState(1_077);
                        match(RPAREN);
                    }
                    break;
                case 7:
                    _localctx = new Con_GD_at_most_onceContext(_localctx);
                    enterOuterAlt(_localctx, 7);
                     {
                        setState(1_079);
                        match(LPAREN);
                        setState(1_080);
                        match(AT_MOST_ONCE);
                        setState(1_081);
                        gD();
                        setState(1_082);
                        match(RPAREN);
                    }
                    break;
                case 8:
                    _localctx = new Con_GD_sometime_afterContext(_localctx);
                    enterOuterAlt(_localctx, 8);
                     {
                        setState(1_084);
                        match(LPAREN);
                        setState(1_085);
                        match(SOMETIME_AFTER);
                        setState(1_086);
                        gD();
                        setState(1_087);
                        gD();
                        setState(1_088);
                        match(RPAREN);
                    }
                    break;
                case 9:
                    _localctx = new Con_GD_sometime_beforeContext(_localctx);
                    enterOuterAlt(_localctx, 9);
                     {
                        setState(1_090);
                        match(LPAREN);
                        setState(1_091);
                        match(SOMETIME_BEFORE);
                        setState(1_092);
                        gD();
                        setState(1_093);
                        gD();
                        setState(1_094);
                        match(RPAREN);
                    }
                    break;
                case 10:
                    _localctx = new Con_GD_always_withinContext(_localctx);
                    enterOuterAlt(_localctx, 10);
                     {
                        setState(1_096);
                        match(LPAREN);
                        setState(1_097);
                        match(ALWAYS_WITHIN);
                        setState(1_098);
                        match(NUMBER);
                        setState(1_099);
                        gD();
                        setState(1_100);
                        gD();
                        setState(1_101);
                        match(RPAREN);
                    }
                    break;
                case 11:
                    _localctx = new Con_GD_hold_duringContext(_localctx);
                    enterOuterAlt(_localctx, 11);
                     {
                        setState(1_103);
                        match(LPAREN);
                        setState(1_104);
                        match(HOLD_DURING);
                        setState(1_105);
                        match(NUMBER);
                        setState(1_106);
                        match(NUMBER);
                        setState(1_107);
                        gD();
                        setState(1_108);
                        match(RPAREN);
                    }
                    break;
                case 12:
                    _localctx = new Con_GD_hold_afterContext(_localctx);
                    enterOuterAlt(_localctx, 12);
                     {
                        setState(1_110);
                        match(LPAREN);
                        setState(1_111);
                        match(HOLD_AFTER);
                        setState(1_112);
                        match(NUMBER);
                        setState(1_113);
                        gD();
                        setState(1_114);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Metric_specContext extends ParserRuleContext {

        public OptimizationContext optimization() {
            return getRuleContext(OptimizationContext.class, 0);
        }

        public Metric_f_expContext metric_f_exp() {
            return getRuleContext(Metric_f_expContext.class, 0);
        }

        public Metric_specContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_metric_spec;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_spec(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_spec(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_spec(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Metric_specContext metric_spec() throws RecognitionException {
        Metric_specContext _localctx = new Metric_specContext(_ctx, getState());
        enterRule(_localctx, 150, RULE_metric_spec);
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(1_118);
                if (!(requirements.contains(":numeric-fluents"))) {
                    throw new FailedPredicateException(this, "requirements.contains(\":numeric-fluents\")");
                }
                setState(1_119);
                match(LPAREN);
                setState(1_120);
                match(METRIC);
                setState(1_121);
                optimization();
                setState(1_122);
                metric_f_exp();
                setState(1_123);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class OptimizationContext extends ParserRuleContext {

        public OptimizationContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_optimization;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterOptimization(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitOptimization(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitOptimization(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final OptimizationContext optimization() throws RecognitionException {
        OptimizationContext _localctx = new OptimizationContext(_ctx, getState());
        enterRule(_localctx, 152, RULE_optimization);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(1_125);
                _la = _input.LA(1);
                if (!(_la == MINIMIZE || _la == MAXIMIZE)) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Metric_f_expContext extends ParserRuleContext {

        public Metric_f_expContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_metric_f_exp;
        }

        public Metric_f_expContext() {
        }

        public void copyFrom(Metric_f_expContext ctx) {
            super.copyFrom(ctx);
        }
    }

    public static class Metric_f_exp_function_symbol_nameContext extends Metric_f_expContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public List<NameContext> name() {
            return getRuleContexts(NameContext.class);
        }

        public NameContext name(int i) {
            return getRuleContext(NameContext.class, i);
        }

        public Metric_f_exp_function_symbol_nameContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_function_symbol_name(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_function_symbol_name(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_function_symbol_name(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Metric_f_exp_minusContext extends Metric_f_expContext {

        public Metric_f_expContext metric_f_exp() {
            return getRuleContext(Metric_f_expContext.class, 0);
        }

        public Metric_f_exp_minusContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_minus(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_minus(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_minus(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Metric_f_exp_function_symbolContext extends Metric_f_expContext {

        public Function_symbolContext function_symbol() {
            return getRuleContext(Function_symbolContext.class, 0);
        }

        public Metric_f_exp_function_symbolContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_function_symbol(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_function_symbol(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_function_symbol(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Metric_f_exp_multiContext extends Metric_f_expContext {

        public Multi_opContext multi_op() {
            return getRuleContext(Multi_opContext.class, 0);
        }

        public List<Metric_f_expContext> metric_f_exp() {
            return getRuleContexts(Metric_f_expContext.class);
        }

        public Metric_f_expContext metric_f_exp(int i) {
            return getRuleContext(Metric_f_expContext.class, i);
        }

        public Metric_f_exp_multiContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_multi(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_multi(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_multi(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Metric_f_exp_numberContext extends Metric_f_expContext {

        public TerminalNode NUMBER() {
            return getToken(PDDLParser.NUMBER, 0);
        }

        public Metric_f_exp_numberContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_number(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_number(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_number(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Metric_f_exp_total_timeContext extends Metric_f_expContext {

        public Metric_f_exp_total_timeContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_total_time(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_total_time(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_total_time(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Metric_f_exp_binaryContext extends Metric_f_expContext {

        public Binary_opContext binary_op() {
            return getRuleContext(Binary_opContext.class, 0);
        }

        public List<Metric_f_expContext> metric_f_exp() {
            return getRuleContexts(Metric_f_expContext.class);
        }

        public Metric_f_expContext metric_f_exp(int i) {
            return getRuleContext(Metric_f_expContext.class, i);
        }

        public Metric_f_exp_binaryContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_binary(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_binary(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_binary(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public static class Metric_f_exp_is_violatedContext extends Metric_f_expContext {

        public Pref_nameContext pref_name() {
            return getRuleContext(Pref_nameContext.class, 0);
        }

        public Metric_f_exp_is_violatedContext(Metric_f_expContext ctx) {
            copyFrom(ctx);
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterMetric_f_exp_is_violated(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitMetric_f_exp_is_violated(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitMetric_f_exp_is_violated(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Metric_f_expContext metric_f_exp() throws RecognitionException {
        Metric_f_expContext _localctx = new Metric_f_expContext(_ctx, getState());
        enterRule(_localctx, 154, RULE_metric_f_exp);
        int _la;
        try {
            int _alt;
            setState(1_169);
            _errHandler.sync(this);
            switch (getInterpreter().adaptivePredict(_input, 107, _ctx)) {
                case 1:
                    _localctx = new Metric_f_exp_binaryContext(_localctx);
                    enterOuterAlt(_localctx, 1);
                     {
                        setState(1_127);
                        match(LPAREN);
                        setState(1_128);
                        binary_op();
                        setState(1_129);
                        metric_f_exp();
                        setState(1_130);
                        metric_f_exp();
                        setState(1_131);
                        match(RPAREN);
                    }
                    break;
                case 2:
                    _localctx = new Metric_f_exp_multiContext(_localctx);
                    enterOuterAlt(_localctx, 2);
                     {
                        setState(1_133);
                        match(LPAREN);
                        setState(1_134);
                        multi_op();
                        setState(1_135);
                        metric_f_exp();
                        setState(1_137);
                        _errHandler.sync(this);
                        _alt = 1;
                        do {
                            switch (_alt) {
                                case 1: {
                                    {
                                        setState(1_136);
                                        metric_f_exp();
                                    }
                                }
                                break;
                                default:
                                    throw new NoViableAltException(this);
                            }
                            setState(1_139);
                            _errHandler.sync(this);
                            _alt = getInterpreter().adaptivePredict(_input, 105, _ctx);
                        } while (_alt != 2 && _alt != org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER);
                        setState(1_141);
                        match(RPAREN);
                    }
                    break;
                case 3:
                    _localctx = new Metric_f_exp_minusContext(_localctx);
                    enterOuterAlt(_localctx, 3);
                     {
                        setState(1_143);
                        match(LPAREN);
                        setState(1_144);
                        match(MINUS);
                        setState(1_145);
                        metric_f_exp();
                        setState(1_146);
                        match(RPAREN);
                    }
                    break;
                case 4:
                    _localctx = new Metric_f_exp_numberContext(_localctx);
                    enterOuterAlt(_localctx, 4);
                     {
                        setState(1_148);
                        match(NUMBER);
                    }
                    break;
                case 5:
                    _localctx = new Metric_f_exp_function_symbol_nameContext(_localctx);
                    enterOuterAlt(_localctx, 5);
                     {
                        setState(1_149);
                        match(LPAREN);
                        setState(1_150);
                        function_symbol();
                        setState(1_154);
                        _errHandler.sync(this);
                        _la = _input.LA(1);
                        while (((((_la - 33)) & ~0x3f) == 0 && ((1L << (_la - 33)) & ((1L << (AT - 33)) | (1L << (OVER - 33)) | (1L << (NAME - 33)))) != 0)) {
                            {
                                {
                                    setState(1_151);
                                    name();
                                }
                            }
                            setState(1_156);
                            _errHandler.sync(this);
                            _la = _input.LA(1);
                        }
                        setState(1_157);
                        match(RPAREN);
                    }
                    break;
                case 6:
                    _localctx = new Metric_f_exp_function_symbolContext(_localctx);
                    enterOuterAlt(_localctx, 6);
                     {
                        setState(1_159);
                        function_symbol();
                    }
                    break;
                case 7:
                    _localctx = new Metric_f_exp_total_timeContext(_localctx);
                    enterOuterAlt(_localctx, 7);
                     {
                        setState(1_160);
                        match(LPAREN);
                        setState(1_161);
                        match(TOTAL_TIME);
                        setState(1_162);
                        match(RPAREN);
                    }
                    break;
                case 8:
                    _localctx = new Metric_f_exp_is_violatedContext(_localctx);
                    enterOuterAlt(_localctx, 8);
                     {
                        setState(1_163);
                        if (!(requirements.contains(":preferences"))) {
                            throw new FailedPredicateException(this, "requirements.contains(\":preferences\")");
                        }
                        setState(1_164);
                        match(LPAREN);
                        setState(1_165);
                        match(IS_VIOLATED);
                        setState(1_166);
                        pref_name();
                        setState(1_167);
                        match(RPAREN);
                    }
                    break;
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Length_specContext extends ParserRuleContext {

        public List<TerminalNode> NUMBER() {
            return getTokens(PDDLParser.NUMBER);
        }

        public TerminalNode NUMBER(int i) {
            return getToken(PDDLParser.NUMBER, i);
        }

        public Length_specContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_length_spec;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterLength_spec(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitLength_spec(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitLength_spec(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Length_specContext length_spec() throws RecognitionException {
        Length_specContext _localctx = new Length_specContext(_ctx, getState());
        enterRule(_localctx, 156, RULE_length_spec);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(1_171);
                match(LPAREN);
                setState(1_172);
                match(LENGTH);
                setState(1_177);
                _errHandler.sync(this);
                switch (getInterpreter().adaptivePredict(_input, 108, _ctx)) {
                    case 1: {
                        setState(1_173);
                        match(LPAREN);
                        setState(1_174);
                        match(SERIAL);
                        setState(1_175);
                        match(NUMBER);
                        setState(1_176);
                        match(RPAREN);
                    }
                    break;
                }
                setState(1_183);
                _errHandler.sync(this);
                _la = _input.LA(1);
                if (_la == LPAREN) {
                    {
                        setState(1_179);
                        match(LPAREN);
                        setState(1_180);
                        match(PARALLEL);
                        setState(1_181);
                        match(NUMBER);
                        setState(1_182);
                        match(RPAREN);
                    }
                }

                setState(1_185);
                match(RPAREN);
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    public static class Require_keyContext extends ParserRuleContext {

        public Require_keyContext(ParserRuleContext parent, int invokingState) {
            super(parent, invokingState);
        }

        @Override
        public int getRuleIndex() {
            return RULE_require_key;
        }

        @Override
        public void enterRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).enterRequire_key(this);
            }
        }

        @Override
        public void exitRule(ParseTreeListener listener) {
            if (listener instanceof PDDLListener) {
                ((PDDLListener) listener).exitRequire_key(this);
            }
        }

        @Override
        public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
            if (visitor instanceof PDDLVisitor) {
                return ((PDDLVisitor<? extends T>) visitor).visitRequire_key(this);
            } else {
                return visitor.visitChildren(this);
            }
        }
    }

    public final Require_keyContext require_key() throws RecognitionException {
        Require_keyContext _localctx = new Require_keyContext(_ctx, getState());
        enterRule(_localctx, 158, RULE_require_key);
        int _la;
        try {
            enterOuterAlt(_localctx, 1);
            {
                setState(1_187);
                _la = _input.LA(1);
                if (!(_la == CONSTRAINTS || _la == STRIPS || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (TYPING - 64)) | (1L << (NEGATIVE_PRECONDITIONS - 64)) | (1L << (DISJUNCTIVE_PRECONDITIONS - 64)) | (1L << (EQUALITY - 64)) | (1L << (EXISTENTIAL_PRECONDITIONS - 64)) | (1L << (UNIVERSAL_PRECONDITIONS - 64)) | (1L << (QUANTIFIED_PRECONDITIONS - 64)) | (1L << (CONDITIONAL_EFFECTS - 64)) | (1L << (FLUENTS - 64)) | (1L << (NUMERIC_FLUENTS - 64)) | (1L << (OBJECT_FLUENTS - 64)) | (1L << (ADL - 64)) | (1L << (DURATIVE_ACTIONS - 64)) | (1L << (DURATION_INEQUALITIES - 64)) | (1L << (CONTINUOUS_EFFECTS - 64)) | (1L << (DERIVED_PREDICATES - 64)) | (1L << (TIMED_INITIAL_LITERALS - 64)) | (1L << (PREFERENCES - 64)) | (1L << (ACTION_COSTS - 64)) | (1L << (GOAL_UTILITIES - 64)))) != 0))) {
                    _errHandler.recoverInline(this);
                } else {
                    if (_input.LA(1) == Token.EOF) {
                        matchedEOF = true;
                    }
                    _errHandler.reportMatch(this);
                    consume();
                }
            }
        } catch (RecognitionException re) {
            _localctx.exception = re;
            _errHandler.reportError(this, re);
            _errHandler.recover(this, re);
        } finally {
            exitRule();
        }
        return _localctx;
    }

    @Override
    public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
        switch (ruleIndex) {
            case 10:
                return functions_def_sempred((Functions_defContext) _localctx, predIndex);
            case 11:
                return function_typed_list_atomic_function_skeleton_sempred((Function_typed_list_atomic_function_skeletonContext) _localctx, predIndex);
            case 12:
                return function_type_sempred((Function_typeContext) _localctx, predIndex);
            case 13:
                return constraints_sempred((ConstraintsContext) _localctx, predIndex);
            case 14:
                return structure_def_sempred((Structure_defContext) _localctx, predIndex);
            case 15:
                return typed_list_name_sempred((Typed_list_nameContext) _localctx, predIndex);
            case 16:
                return typed_list_variable_sempred((Typed_list_variableContext) _localctx, predIndex);
            case 26:
                return pre_GD_sempred((Pre_GDContext) _localctx, predIndex);
            case 27:
                return pref_GD_sempred((Pref_GDContext) _localctx, predIndex);
            case 29:
                return gD_sempred((GDContext) _localctx, predIndex);
            case 33:
                return atomic_formula_term_sempred((Atomic_formula_termContext) _localctx, predIndex);
            case 34:
                return atomic_formula_name_sempred((Atomic_formula_nameContext) _localctx, predIndex);
            case 35:
                return term_sempred((TermContext) _localctx, predIndex);
            case 36:
                return function_term_sempred((Function_termContext) _localctx, predIndex);
            case 37:
                return f_exp_sempred((F_expContext) _localctx, predIndex);
            case 44:
                return c_effect_sempred((C_effectContext) _localctx, predIndex);
            case 45:
                return p_effect_sempred((P_effectContext) _localctx, predIndex);
            case 51:
                return da_GD_sempred((Da_GDContext) _localctx, predIndex);
            case 52:
                return pref_timed_GD_sempred((Pref_timed_GDContext) _localctx, predIndex);
            case 56:
                return duration_constraint_sempred((Duration_constraintContext) _localctx, predIndex);
            case 58:
                return d_op_sempred((D_opContext) _localctx, predIndex);
            case 59:
                return d_value_sempred((D_valueContext) _localctx, predIndex);
            case 60:
                return da_effect_sempred((Da_effectContext) _localctx, predIndex);
            case 61:
                return timed_effect_sempred((Timed_effectContext) _localctx, predIndex);
            case 63:
                return f_exp_da_sempred((F_exp_daContext) _localctx, predIndex);
            case 70:
                return init_el_sempred((Init_elContext) _localctx, predIndex);
            case 73:
                return pref_con_GD_sempred((Pref_con_GDContext) _localctx, predIndex);
            case 75:
                return metric_spec_sempred((Metric_specContext) _localctx, predIndex);
            case 77:
                return metric_f_exp_sempred((Metric_f_expContext) _localctx, predIndex);
        }
        return true;
    }

    private boolean functions_def_sempred(Functions_defContext _localctx, int predIndex) {
        switch (predIndex) {
            case 0:
                return requirements.contains(":fluents") || requirements.contains(":numeric-fluents") || requirements.contains(":object-fluents");
        }
        return true;
    }

    private boolean function_typed_list_atomic_function_skeleton_sempred(Function_typed_list_atomic_function_skeletonContext _localctx, int predIndex) {
        switch (predIndex) {
            case 1:
                return requirements.contains(":numeric-fluents");
        }
        return true;
    }

    private boolean function_type_sempred(Function_typeContext _localctx, int predIndex) {
        switch (predIndex) {
            case 2:
                return requirements.contains(":numeric-fluents");
            case 3:
                return requirements.contains(":typing") && requirements.contains(":object-fluents");
        }
        return true;
    }

    private boolean constraints_sempred(ConstraintsContext _localctx, int predIndex) {
        switch (predIndex) {
            case 4:
                return requirements.contains(":constraints");
            case 5:
                return requirements.contains(":constraints");
        }
        return true;
    }

    private boolean structure_def_sempred(Structure_defContext _localctx, int predIndex) {
        switch (predIndex) {
            case 6:
                return requirements.contains(":durative-actions");
            case 7:
                return requirements.contains(":derived-predicates");
        }
        return true;
    }

    private boolean typed_list_name_sempred(Typed_list_nameContext _localctx, int predIndex) {
        switch (predIndex) {
            case 8:
                return requirements.contains(":typing");
        }
        return true;
    }

    private boolean typed_list_variable_sempred(Typed_list_variableContext _localctx, int predIndex) {
        switch (predIndex) {
            case 9:
                return requirements.contains(":typing");
        }
        return true;
    }

    private boolean pre_GD_sempred(Pre_GDContext _localctx, int predIndex) {
        switch (predIndex) {
            case 10:
                return requirements.contains(":universal-preconditions");
        }
        return true;
    }

    private boolean pref_GD_sempred(Pref_GDContext _localctx, int predIndex) {
        switch (predIndex) {
            case 11:
                return requirements.contains(":preferences");
        }
        return true;
    }

    private boolean gD_sempred(GDContext _localctx, int predIndex) {
        switch (predIndex) {
            case 12:
                return requirements.contains(":negative-preconditions");
            case 13:
                return requirements.contains(":disjunctive-preconditions");
            case 14:
                return requirements.contains(":disjunctive-preconditions");
            case 15:
                return requirements.contains(":disjunctive-preconditions");
            case 16:
                return requirements.contains(":existential-preconditions");
            case 17:
                return requirements.contains(":universal-preconditions");
            case 18:
                return requirements.contains(":numeric-fluents");
        }
        return true;
    }

    private boolean atomic_formula_term_sempred(Atomic_formula_termContext _localctx, int predIndex) {
        switch (predIndex) {
            case 19:
                return requirements.contains(":equality");
        }
        return true;
    }

    private boolean atomic_formula_name_sempred(Atomic_formula_nameContext _localctx, int predIndex) {
        switch (predIndex) {
            case 20:
                return requirements.contains(":equality");
        }
        return true;
    }

    private boolean term_sempred(TermContext _localctx, int predIndex) {
        switch (predIndex) {
            case 21:
                return requirements.contains(":object-fluents");
        }
        return true;
    }

    private boolean function_term_sempred(Function_termContext _localctx, int predIndex) {
        switch (predIndex) {
            case 22:
                return requirements.contains(":object-fluents");
        }
        return true;
    }

    private boolean f_exp_sempred(F_expContext _localctx, int predIndex) {
        switch (predIndex) {
            case 23:
                return requirements.contains(":numeric-fluents");
            case 24:
                return requirements.contains(":numeric-fluents");
            case 25:
                return requirements.contains(":numeric-fluents");
            case 26:
                return requirements.contains(":numeric-fluents");
            case 27:
                return requirements.contains(":numeric-fluents");
        }
        return true;
    }

    private boolean c_effect_sempred(C_effectContext _localctx, int predIndex) {
        switch (predIndex) {
            case 28:
                return requirements.contains(":conditional-effects");
            case 29:
                return requirements.contains(":conditional-effects");
        }
        return true;
    }

    private boolean p_effect_sempred(P_effectContext _localctx, int predIndex) {
        switch (predIndex) {
            case 30:
                return requirements.contains(":numeric-fluents");
            case 31:
                return requirements.contains(":object-fluents");
            case 32:
                return requirements.contains(":object-fluents");
        }
        return true;
    }

    private boolean da_GD_sempred(Da_GDContext _localctx, int predIndex) {
        switch (predIndex) {
            case 33:
                return requirements.contains(":universal-preconditions");
        }
        return true;
    }

    private boolean pref_timed_GD_sempred(Pref_timed_GDContext _localctx, int predIndex) {
        switch (predIndex) {
            case 34:
                return requirements.contains(":preferences");
        }
        return true;
    }

    private boolean duration_constraint_sempred(Duration_constraintContext _localctx, int predIndex) {
        switch (predIndex) {
            case 35:
                return requirements.contains(":duration-inequalities");
        }
        return true;
    }

    private boolean d_op_sempred(D_opContext _localctx, int predIndex) {
        switch (predIndex) {
            case 36:
                return requirements.contains(":duration-inequalities");
            case 37:
                return requirements.contains(":duration-inequalities");
        }
        return true;
    }

    private boolean d_value_sempred(D_valueContext _localctx, int predIndex) {
        switch (predIndex) {
            case 38:
                return requirements.contains(":numeric-fluents");
        }
        return true;
    }

    private boolean da_effect_sempred(Da_effectContext _localctx, int predIndex) {
        switch (predIndex) {
            case 39:
                return requirements.contains(":conditional-effects");
            case 40:
                return requirements.contains(":conditional-effects");
        }
        return true;
    }

    private boolean timed_effect_sempred(Timed_effectContext _localctx, int predIndex) {
        switch (predIndex) {
            case 41:
                return requirements.contains(":numeric-fluents");
            case 42:
                return requirements.contains(":continuous-effects") && requirements.contains(":numeric-fluents");
        }
        return true;
    }

    private boolean f_exp_da_sempred(F_exp_daContext _localctx, int predIndex) {
        switch (predIndex) {
            case 43:
                return requirements.contains(":duration-inequalities");
        }
        return true;
    }

    private boolean init_el_sempred(Init_elContext _localctx, int predIndex) {
        switch (predIndex) {
            case 44:
                return requirements.contains(":timed-initial-literals");
            case 45:
                return requirements.contains(":numeric-fluents");
            case 46:
                return requirements.contains(":object-fluents");
        }
        return true;
    }

    private boolean pref_con_GD_sempred(Pref_con_GDContext _localctx, int predIndex) {
        switch (predIndex) {
            case 47:
                return requirements.contains(":universal-preconditions");
            case 48:
                return requirements.contains(":preferences");
        }
        return true;
    }

    private boolean metric_spec_sempred(Metric_specContext _localctx, int predIndex) {
        switch (predIndex) {
            case 49:
                return requirements.contains(":numeric-fluents");
        }
        return true;
    }

    private boolean metric_f_exp_sempred(Metric_f_expContext _localctx, int predIndex) {
        switch (predIndex) {
            case 50:
                return requirements.contains(":preferences");
        }
        return true;
    }
    public static final String _serializedATN
            = "\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3e\u04a8\4\2\t\2\4"
            + "\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"
            + "\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"
            + "\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"
            + "\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"
            + "\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"
            + ",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"
            + "\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="
            + "\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"
            + "\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\3\2\3\2\3\2\3\2\3"
            + "\2\3\2\3\2\5\2\u00aa\n\2\3\2\5\2\u00ad\n\2\3\2\5\2\u00b0\n\2\3\2\5\2\u00b3"
            + "\n\2\3\2\5\2\u00b6\n\2\3\2\5\2\u00b9\n\2\3\2\7\2\u00bc\n\2\f\2\16\2\u00bf"
            + "\13\2\3\2\3\2\3\3\3\3\3\3\6\3\u00c6\n\3\r\3\16\3\u00c7\3\3\3\3\3\4\3\4"
            + "\3\4\5\4\u00cf\n\4\3\4\3\4\3\5\3\5\3\5\5\5\u00d6\n\5\3\5\3\5\3\6\3\6\3"
            + "\6\6\6\u00dd\n\6\r\6\16\6\u00de\3\6\3\6\3\7\3\7\3\7\5\7\u00e6\n\7\3\7"
            + "\3\7\3\b\3\b\3\t\3\t\3\t\3\n\3\n\3\n\5\n\u00f2\n\n\3\n\3\n\3\13\3\13\3"
            + "\f\3\f\3\f\3\f\5\f\u00fc\n\f\3\f\3\f\3\r\3\r\6\r\u0102\n\r\r\r\16\r\u0103"
            + "\3\r\6\r\u0107\n\r\r\r\16\r\u0108\3\r\3\r\3\r\5\r\u010e\n\r\5\r\u0110"
            + "\n\r\3\16\3\16\3\16\3\16\5\16\u0116\n\16\3\17\3\17\3\17\3\17\3\17\3\17"
            + "\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u0124\n\17\3\20\3\20\3\20\3\20\3\20"
            + "\5\20\u012b\n\20\3\21\6\21\u012e\n\21\r\21\16\21\u012f\3\21\3\21\6\21"
            + "\u0134\n\21\r\21\16\21\u0135\3\21\3\21\3\21\5\21\u013b\n\21\5\21\u013d"
            + "\n\21\3\22\6\22\u0140\n\22\r\22\16\22\u0141\3\22\3\22\6\22\u0146\n\22"
            + "\r\22\16\22\u0147\3\22\3\22\3\22\5\22\u014d\n\22\5\22\u014f\n\22\3\23"
            + "\3\23\5\23\u0153\n\23\3\24\3\24\3\24\6\24\u0158\n\24\r\24\16\24\u0159"
            + "\3\24\3\24\3\24\5\24\u015f\n\24\3\25\3\25\3\25\5\25\u0164\n\25\3\26\3"
            + "\26\3\26\5\26\u0169\n\26\3\27\3\27\3\27\5\27\u016e\n\27\3\30\3\30\3\30"
            + "\5\30\u0173\n\30\3\31\3\31\3\31\3\31\3\31\3\31\5\31\u017b\n\31\3\31\3"
            + "\31\3\31\3\31\3\32\3\32\3\33\3\33\5\33\u0185\n\33\3\33\3\33\5\33\u0189"
            + "\n\33\3\34\3\34\3\34\3\34\7\34\u018f\n\34\f\34\16\34\u0192\13\34\3\34"
            + "\3\34\3\34\3\34\3\34\3\34\5\34\u019a\n\34\3\34\3\34\3\34\3\34\5\34\u01a0"
            + "\n\34\3\35\3\35\3\35\3\35\5\35\u01a6\n\35\3\35\3\35\3\35\3\35\5\35\u01ac"
            + "\n\35\3\36\3\36\3\37\3\37\3\37\3\37\3\37\3\37\7\37\u01b6\n\37\f\37\16"
            + "\37\u01b9\13\37\3\37\3\37\3\37\3\37\3\37\7\37\u01c0\n\37\f\37\16\37\u01c3"
            + "\13\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37"
            + "\3\37\3\37\3\37\3\37\3\37\3\37\5\37\u01d8\n\37\3\37\3\37\3\37\3\37\3\37"
            + "\3\37\3\37\3\37\3\37\5\37\u01e3\n\37\3\37\3\37\3\37\3\37\3\37\3\37\5\37"
            + "\u01eb\n\37\3 \3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\5!\u01f9\n!\3\"\3\"\3"
            + "\"\3\"\3\"\3\"\5\"\u0201\n\"\3#\3#\3#\7#\u0206\n#\f#\16#\u0209\13#\3#"
            + "\3#\3#\3#\3#\3#\3#\3#\3#\5#\u0214\n#\3$\3$\3$\7$\u0219\n$\f$\16$\u021c"
            + "\13$\3$\3$\3$\3$\3$\3$\3$\3$\3$\5$\u0227\n$\3%\3%\3%\3%\5%\u022d\n%\3"
            + "&\3&\3&\3&\7&\u0233\n&\f&\16&\u0236\13&\3&\3&\3\'\3\'\3\'\3\'\3\'\3\'"
            + "\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\6\'\u0248\n\'\r\'\16\'\u0249\3\'\3\'"
            + "\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\5\'\u0256\n\'\3(\3(\3(\7(\u025b\n(\f"
            + "(\16(\u025e\13(\3(\3(\3(\5(\u0263\n(\3)\3)\5)\u0267\n)\3*\3*\3+\3+\3,"
            + "\3,\3-\3-\3-\7-\u0272\n-\f-\16-\u0275\13-\3-\3-\5-\u0279\n-\3.\3.\3.\3"
            + ".\3.\5.\u0280\n.\3.\3.\3.\3.\3.\3.\3.\3.\3.\3.\3.\3.\5.\u028e\n.\3/\3"
            + "/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3/\3"
            + "/\3/\3/\5/\u02ab\n/\3\60\3\60\3\60\7\60\u02b0\n\60\f\60\16\60\u02b3\13"
            + "\60\3\60\3\60\5\60\u02b7\n\60\3\61\3\61\3\62\3\62\3\62\3\62\3\62\3\62"
            + "\5\62\u02c1\n\62\3\62\3\62\3\62\3\62\3\63\3\63\3\64\3\64\3\64\3\64\3\64"
            + "\3\64\3\64\3\65\3\65\3\65\3\65\7\65\u02d4\n\65\f\65\16\65\u02d7\13\65"
            + "\3\65\3\65\3\65\3\65\3\65\3\65\5\65\u02df\n\65\3\65\3\65\3\65\3\65\5\65"
            + "\u02e5\n\65\3\66\3\66\3\66\3\66\3\66\5\66\u02ec\n\66\3\66\3\66\3\66\5"
            + "\66\u02f1\n\66\3\67\3\67\3\67\3\67\3\67\3\67\3\67\3\67\3\67\3\67\3\67"
            + "\3\67\5\67\u02ff\n\67\38\38\39\39\3:\3:\3:\3:\6:\u0309\n:\r:\16:\u030a"
            + "\3:\3:\3:\3:\3:\5:\u0312\n:\3;\3;\3;\3;\3;\3;\3;\3;\3;\3;\3;\3;\5;\u0320"
            + "\n;\3<\3<\3<\3<\3<\5<\u0327\n<\3=\3=\3=\5=\u032c\n=\3>\3>\3>\7>\u0331"
            + "\n>\f>\16>\u0334\13>\3>\3>\3>\3>\3>\3>\3>\5>\u033d\n>\3>\3>\3>\3>\3>\3"
            + ">\3>\3>\3>\3>\3>\5>\u034a\n>\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3"
            + "?\3?\3?\3?\3?\3?\3?\5?\u0360\n?\3@\3@\3@\3@\3@\3@\3A\3A\3A\3A\3A\3A\3"
            + "A\3A\3A\3A\6A\u0372\nA\rA\16A\u0373\3A\3A\3A\3A\3A\3A\3A\3A\3A\3A\5A\u0380"
            + "\nA\3B\3B\3C\3C\3C\3C\3C\3C\3C\3C\3C\3C\3C\3C\3C\5C\u0391\nC\3D\3D\3D"
            + "\3D\3D\3D\3E\3E\3E\3E\3E\3E\3E\3E\3E\3E\3E\5E\u03a4\nE\3E\5E\u03a7\nE"
            + "\3E\3E\3E\5E\u03ac\nE\3E\5E\u03af\nE\3E\5E\u03b2\nE\3E\3E\3F\3F\3F\5F"
            + "\u03b9\nF\3F\3F\3G\3G\3G\7G\u03c0\nG\fG\16G\u03c3\13G\3G\3G\3H\3H\3H\3"
            + "H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\3H\5H\u03dd\nH\3"
            + "I\3I\3I\3I\7I\u03e3\nI\fI\16I\u03e6\13I\3I\3I\5I\u03ea\nI\3J\3J\3J\3J"
            + "\3J\3K\3K\3K\7K\u03f4\nK\fK\16K\u03f7\13K\3K\3K\3K\3K\3K\3K\5K\u03ff\n"
            + "K\3K\3K\3K\3K\3K\3K\3K\3K\5K\u0409\nK\3K\3K\3K\3K\5K\u040f\nK\3L\3L\3"
            + "L\7L\u0414\nL\fL\16L\u0417\13L\3L\3L\3L\3L\3L\5L\u041e\nL\3L\3L\3L\3L"
            + "\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L"
            + "\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L"
            + "\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\3L\5L\u045f\nL\3M\3M\3M\3M\3M\3M"
            + "\3M\3N\3N\3O\3O\3O\3O\3O\3O\3O\3O\3O\3O\6O\u0474\nO\rO\16O\u0475\3O\3"
            + "O\3O\3O\3O\3O\3O\3O\3O\3O\3O\7O\u0483\nO\fO\16O\u0486\13O\3O\3O\3O\3O"
            + "\3O\3O\3O\3O\3O\3O\3O\3O\5O\u0494\nO\3P\3P\3P\3P\3P\3P\5P\u049c\nP\3P"
            + "\3P\3P\3P\5P\u04a2\nP\3P\3P\3Q\3Q\3Q\2\2R\2\4\6\b\n\f\16\20\22\24\26\30"
            + "\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`bdfhjlnprtvxz|~\u0080"
            + "\u0082\u0084\u0086\u0088\u008a\u008c\u008e\u0090\u0092\u0094\u0096\u0098"
            + "\u009a\u009c\u009e\u00a0\2\13\4\2ZZ\\\\\4\2YY[[\3\2]a\4\2#$bb\4\2\32\32"
            + "\34\37\3\2%&\3\2\36\37\3\2:;\4\2\13\13AU\2\u04f4\2\u00a2\3\2\2\2\4\u00c2"
            + "\3\2\2\2\6\u00cb\3\2\2\2\b\u00d2\3\2\2\2\n\u00d9\3\2\2\2\f\u00e2\3\2\2"
            + "\2\16\u00e9\3\2\2\2\20\u00eb\3\2\2\2\22\u00ee\3\2\2\2\24\u00f5\3\2\2\2"
            + "\26\u00f7\3\2\2\2\30\u010f\3\2\2\2\32\u0115\3\2\2\2\34\u0123\3\2\2\2\36"
            + "\u012a\3\2\2\2 \u013c\3\2\2\2\"\u014e\3\2\2\2$\u0152\3\2\2\2&\u015e\3"
            + "\2\2\2(\u0163\3\2\2\2*\u0168\3\2\2\2,\u016d\3\2\2\2.\u0172\3\2\2\2\60"
            + "\u0174\3\2\2\2\62\u0180\3\2\2\2\64\u0184\3\2\2\2\66\u019f\3\2\2\28\u01ab"
            + "\3\2\2\2:\u01ad\3\2\2\2<\u01ea\3\2\2\2>\u01ec\3\2\2\2@\u01f8\3\2\2\2B"
            + "\u0200\3\2\2\2D\u0213\3\2\2\2F\u0226\3\2\2\2H\u022c\3\2\2\2J\u022e\3\2"
            + "\2\2L\u0255\3\2\2\2N\u0262\3\2\2\2P\u0266\3\2\2\2R\u0268\3\2\2\2T\u026a"
            + "\3\2\2\2V\u026c\3\2\2\2X\u0278\3\2\2\2Z\u028d\3\2\2\2\\\u02aa\3\2\2\2"
            + "^\u02b6\3\2\2\2`\u02b8\3\2\2\2b\u02ba\3\2\2\2d\u02c6\3\2\2\2f\u02c8\3"
            + "\2\2\2h\u02e4\3\2\2\2j\u02f0\3\2\2\2l\u02fe\3\2\2\2n\u0300\3\2\2\2p\u0302"
            + "\3\2\2\2r\u0311\3\2\2\2t\u031f\3\2\2\2v\u0326\3\2\2\2x\u032b\3\2\2\2z"
            + "\u0349\3\2\2\2|\u035f\3\2\2\2~\u0361\3\2\2\2\u0080\u037f\3\2\2\2\u0082"
            + "\u0381\3\2\2\2\u0084\u0390\3\2\2\2\u0086\u0392\3\2\2\2\u0088\u0398\3\2"
            + "\2\2\u008a\u03b5\3\2\2\2\u008c\u03bc\3\2\2\2\u008e\u03dc\3\2\2\2\u0090"
            + "\u03e9\3\2\2\2\u0092\u03eb\3\2\2\2\u0094\u040e\3\2\2\2\u0096\u045e\3\2"
            + "\2\2\u0098\u0460\3\2\2\2\u009a\u0467\3\2\2\2\u009c\u0493\3\2\2\2\u009e"
            + "\u0495\3\2\2\2\u00a0\u04a5\3\2\2\2\u00a2\u00a3\7W\2\2\u00a3\u00a4\7\3"
            + "\2\2\u00a4\u00a5\7W\2\2\u00a5\u00a6\7\4\2\2\u00a6\u00a7\5V,\2\u00a7\u00a9"
            + "\7X\2\2\u00a8\u00aa\5\4\3\2\u00a9\u00a8\3\2\2\2\u00a9\u00aa\3\2\2\2\u00aa"
            + "\u00ac\3\2\2\2\u00ab\u00ad\5\6\4\2\u00ac\u00ab\3\2\2\2\u00ac\u00ad\3\2"
            + "\2\2\u00ad\u00af\3\2\2\2\u00ae\u00b0\5\b\5\2\u00af\u00ae\3\2\2\2\u00af"
            + "\u00b0\3\2\2\2\u00b0\u00b2\3\2\2\2\u00b1\u00b3\5\n\6\2\u00b2\u00b1\3\2"
            + "\2\2\u00b2\u00b3\3\2\2\2\u00b3\u00b5\3\2\2\2\u00b4\u00b6\5\26\f\2\u00b5"
            + "\u00b4\3\2\2\2\u00b5\u00b6\3\2\2\2\u00b6\u00b8\3\2\2\2\u00b7\u00b9\5\34"
            + "\17\2\u00b8\u00b7\3\2\2\2\u00b8\u00b9\3\2\2\2\u00b9\u00bd\3\2\2\2\u00ba"
            + "\u00bc\5\36\20\2\u00bb\u00ba\3\2\2\2\u00bc\u00bf\3\2\2\2\u00bd\u00bb\3"
            + "\2\2\2\u00bd\u00be\3\2\2\2\u00be\u00c0\3\2\2\2\u00bf\u00bd\3\2\2\2\u00c0"
            + "\u00c1\7X\2\2\u00c1\3\3\2\2\2\u00c2\u00c3\7W\2\2\u00c3\u00c5\7\5\2\2\u00c4"
            + "\u00c6\5\u00a0Q\2\u00c5\u00c4\3\2\2\2\u00c6\u00c7\3\2\2\2\u00c7\u00c5"
            + "\3\2\2\2\u00c7\u00c8\3\2\2\2\u00c8\u00c9\3\2\2\2\u00c9\u00ca\7X\2\2\u00ca"
            + "\5\3\2\2\2\u00cb\u00cc\7W\2\2\u00cc\u00ce\7\6\2\2\u00cd\u00cf\5 \21\2"
            + "\u00ce\u00cd\3\2\2\2\u00ce\u00cf\3\2\2\2\u00cf\u00d0\3\2\2\2\u00d0\u00d1"
            + "\7X\2\2\u00d1\7\3\2\2\2\u00d2\u00d3\7W\2\2\u00d3\u00d5\7\7\2\2\u00d4\u00d6"
            + "\5 \21\2\u00d5\u00d4\3\2\2\2\u00d5\u00d6\3\2\2\2\u00d6\u00d7\3\2\2\2\u00d7"
            + "\u00d8\7X\2\2\u00d8\t\3\2\2\2\u00d9\u00da\7W\2\2\u00da\u00dc\7\b\2\2\u00db"
            + "\u00dd\5\f\7\2\u00dc\u00db\3\2\2\2\u00dd\u00de\3\2\2\2\u00de\u00dc\3\2"
            + "\2\2\u00de\u00df\3\2\2\2\u00df\u00e0\3\2\2\2\u00e0\u00e1\7X\2\2\u00e1"
            + "\13\3\2\2\2\u00e2\u00e3\7W\2\2\u00e3\u00e5\5\16\b\2\u00e4\u00e6\5\"\22"
            + "\2\u00e5\u00e4\3\2\2\2\u00e5\u00e6\3\2\2\2\u00e6\u00e7\3\2\2\2\u00e7\u00e8"
            + "\7X\2\2\u00e8\r\3\2\2\2\u00e9\u00ea\5V,\2\u00ea\17\3\2\2\2\u00eb\u00ec"
            + "\7V\2\2\u00ec\u00ed\5V,\2\u00ed\21\3\2\2\2\u00ee\u00ef\7W\2\2\u00ef\u00f1"
            + "\5\24\13\2\u00f0\u00f2\5\"\22\2\u00f1\u00f0\3\2\2\2\u00f1\u00f2\3\2\2"
            + "\2\u00f2\u00f3\3\2\2\2\u00f3\u00f4\7X\2\2\u00f4\23\3\2\2\2\u00f5\u00f6"
            + "\5V,\2\u00f6\25\3\2\2\2\u00f7\u00f8\6\f\2\2\u00f8\u00f9\7W\2\2\u00f9\u00fb"
            + "\7\t\2\2\u00fa\u00fc\5\30\r\2\u00fb\u00fa\3\2\2\2\u00fb\u00fc\3\2\2\2"
            + "\u00fc\u00fd\3\2\2\2\u00fd\u00fe\7X\2\2\u00fe\27\3\2\2\2\u00ff\u0101\6"
            + "\r\3\2\u0100\u0102\5\22\n\2\u0101\u0100\3\2\2\2\u0102\u0103\3\2\2\2\u0103"
            + "\u0101\3\2\2\2\u0103\u0104\3\2\2\2\u0104\u0110\3\2\2\2\u0105\u0107\5\22"
            + "\n\2\u0106\u0105\3\2\2\2\u0107\u0108\3\2\2\2\u0108\u0106\3\2\2\2\u0108"
            + "\u0109\3\2\2\2\u0109\u010a\3\2\2\2\u010a\u010b\7Z\2\2\u010b\u010d\5\32"
            + "\16\2\u010c\u010e\5\30\r\2\u010d\u010c\3\2\2\2\u010d\u010e\3\2\2\2\u010e"
            + "\u0110\3\2\2\2\u010f\u00ff\3\2\2\2\u010f\u0106\3\2\2\2\u0110\31\3\2\2"
            + "\2\u0111\u0112\6\16\4\2\u0112\u0116\7\n\2\2\u0113\u0114\6\16\5\2\u0114"
            + "\u0116\5&\24\2\u0115\u0111\3\2\2\2\u0115\u0113\3\2\2\2\u0116\33\3\2\2"
            + "\2\u0117\u0118\6\17\6\2\u0118\u0119\7W\2\2\u0119\u011a\7\13\2\2\u011a"
            + "\u011b\5\u0096L\2\u011b\u011c\7X\2\2\u011c\u0124\3\2\2\2\u011d\u011e\6"
            + "\17\7\2\u011e\u011f\7W\2\2\u011f\u0120\7\13\2\2\u0120\u0121\5\u0094K\2"
            + "\u0121\u0122\7X\2\2\u0122\u0124\3\2\2\2\u0123\u0117\3\2\2\2\u0123\u011d"
            + "\3\2\2\2\u0124\35\3\2\2\2\u0125\u012b\5\60\31\2\u0126\u0127\6\20\b\2\u0127"
            + "\u012b\5b\62\2\u0128\u0129\6\20\t\2\u0129\u012b\5\u0086D\2\u012a\u0125"
            + "\3\2\2\2\u012a\u0126\3\2\2\2\u012a\u0128\3\2\2\2\u012b\37\3\2\2\2\u012c"
            + "\u012e\5V,\2\u012d\u012c\3\2\2\2\u012e\u012f\3\2\2\2\u012f\u012d\3\2\2"
            + "\2\u012f\u0130\3\2\2\2\u0130\u013d\3\2\2\2\u0131\u0133\6\21\n\2\u0132"
            + "\u0134\5V,\2\u0133\u0132\3\2\2\2\u0134\u0135\3\2\2\2\u0135\u0133\3\2\2"
            + "\2\u0135\u0136\3\2\2\2\u0136\u0137\3\2\2\2\u0137\u0138\7Z\2\2\u0138\u013a"
            + "\5&\24\2\u0139\u013b\5 \21\2\u013a\u0139\3\2\2\2\u013a\u013b\3\2\2\2\u013b"
            + "\u013d\3\2\2\2\u013c\u012d\3\2\2\2\u013c\u0131\3\2\2\2\u013d!\3\2\2\2"
            + "\u013e\u0140\5\20\t\2\u013f\u013e\3\2\2\2\u0140\u0141\3\2\2\2\u0141\u013f"
            + "\3\2\2\2\u0141\u0142\3\2\2\2\u0142\u014f\3\2\2\2\u0143\u0145\6\22\13\2"
            + "\u0144\u0146\5\20\t\2\u0145\u0144\3\2\2\2\u0146\u0147\3\2\2\2\u0147\u0145"
            + "\3\2\2\2\u0147\u0148\3\2\2\2\u0148\u0149\3\2\2\2\u0149\u014a\7Z\2\2\u014a"
            + "\u014c\5&\24\2\u014b\u014d\5\"\22\2\u014c\u014b\3\2\2\2\u014c\u014d\3"
            + "\2\2\2\u014d\u014f\3\2\2\2\u014e\u013f\3\2\2\2\u014e\u0143\3\2\2\2\u014f"
            + "#\3\2\2\2\u0150\u0153\5V,\2\u0151\u0153\7\f\2\2\u0152\u0150\3\2\2\2\u0152"
            + "\u0151\3\2\2\2\u0153%\3\2\2\2\u0154\u0155\7W\2\2\u0155\u0157\7\r\2\2\u0156"
            + "\u0158\5$\23\2\u0157\u0156\3\2\2\2\u0158\u0159\3\2\2\2\u0159\u0157\3\2"
            + "\2\2\u0159\u015a\3\2\2\2\u015a\u015b\3\2\2\2\u015b\u015c\7X\2\2\u015c"
            + "\u015f\3\2\2\2\u015d\u015f\5$\23\2\u015e\u0154\3\2\2\2\u015e\u015d\3\2"
            + "\2\2\u015f\'\3\2\2\2\u0160\u0161\7W\2\2\u0161\u0164\7X\2\2\u0162\u0164"
            + "\5\66\34\2\u0163\u0160\3\2\2\2\u0163\u0162\3\2\2\2\u0164)\3\2\2\2\u0165"
            + "\u0166\7W\2\2\u0166\u0169\7X\2\2\u0167\u0169\5X-\2\u0168\u0165\3\2\2\2"
            + "\u0168\u0167\3\2\2\2\u0169+\3\2\2\2\u016a\u016b\7W\2\2\u016b\u016e\7X"
            + "\2\2\u016c\u016e\5h\65\2\u016d\u016a\3\2\2\2\u016d\u016c\3\2\2\2\u016e"
            + "-\3\2\2\2\u016f\u0170\7W\2\2\u0170\u0173\7X\2\2\u0171\u0173\5z>\2\u0172"
            + "\u016f\3\2\2\2\u0172\u0171\3\2\2\2\u0173/\3\2\2\2\u0174\u0175\7W\2\2\u0175"
            + "\u0176\7\16\2\2\u0176\u0177\5\62\32\2\u0177\u0178\7\17\2\2\u0178\u017a"
            + "\7W\2\2\u0179\u017b\5\"\22\2\u017a\u0179\3\2\2\2\u017a\u017b\3\2\2\2\u017b"
            + "\u017c\3\2\2\2\u017c\u017d\7X\2\2\u017d\u017e\5\64\33\2\u017e\u017f\7"
            + "X\2\2\u017f\61\3\2\2\2\u0180\u0181\5V,\2\u0181\63\3\2\2\2\u0182\u0183"
            + "\7\20\2\2\u0183\u0185\5(\25\2\u0184\u0182\3\2\2\2\u0184\u0185\3\2\2\2"
            + "\u0185\u0188\3\2\2\2\u0186\u0187\7\21\2\2\u0187\u0189\5*\26\2\u0188\u0186"
            + "\3\2\2\2\u0188\u0189\3\2\2\2\u0189\65\3\2\2\2\u018a\u01a0\58\35\2\u018b"
            + "\u018c\7W\2\2\u018c\u0190\7\22\2\2\u018d\u018f\5\66\34\2\u018e\u018d\3"
            + "\2\2\2\u018f\u0192\3\2\2\2\u0190\u018e\3\2\2\2\u0190\u0191\3\2\2\2\u0191"
            + "\u0193\3\2\2\2\u0192\u0190\3\2\2\2\u0193\u01a0\7X\2\2\u0194\u0195\6\34"
            + "\f\2\u0195\u0196\7W\2\2\u0196\u0197\7\27\2\2\u0197\u0199\7W\2\2\u0198"
            + "\u019a\5\"\22\2\u0199\u0198\3\2\2\2\u0199\u019a\3\2\2\2\u019a\u019b\3"
            + "\2\2\2\u019b\u019c\7X\2\2\u019c\u019d\5\66\34\2\u019d\u019e\7X\2\2\u019e"
            + "\u01a0\3\2\2\2\u019f\u018a\3\2\2\2\u019f\u018b\3\2\2\2\u019f\u0194\3\2"
            + "\2\2\u01a0\67\3\2\2\2\u01a1\u01a2\6\35\r\2\u01a2\u01a3\7W\2\2\u01a3\u01a5"
            + "\7\30\2\2\u01a4\u01a6\5:\36\2\u01a5\u01a4\3\2\2\2\u01a5\u01a6\3\2\2\2"
            + "\u01a6\u01a7\3\2\2\2\u01a7\u01a8\5<\37\2\u01a8\u01a9\7X\2\2\u01a9\u01ac"
            + "\3\2\2\2\u01aa\u01ac\5<\37\2\u01ab\u01a1\3\2\2\2\u01ab\u01aa\3\2\2\2\u01ac"
            + "9\3\2\2\2\u01ad\u01ae\5V,\2\u01ae;\3\2\2\2\u01af\u01eb\5D#\2\u01b0\u01b1"
            + "\6\37\16\2\u01b1\u01eb\5@!\2\u01b2\u01b3\7W\2\2\u01b3\u01b7\7\22\2\2\u01b4"
            + "\u01b6\5<\37\2\u01b5\u01b4\3\2\2\2\u01b6\u01b9\3\2\2\2\u01b7\u01b5\3\2"
            + "\2\2\u01b7\u01b8\3\2\2\2\u01b8\u01ba\3\2\2\2\u01b9\u01b7\3\2\2\2\u01ba"
            + "\u01eb\7X\2\2\u01bb\u01bc\6\37\17\2\u01bc\u01bd\7W\2\2\u01bd\u01c1\7\23"
            + "\2\2\u01be\u01c0\5<\37\2\u01bf\u01be\3\2\2\2\u01c0\u01c3\3\2\2\2\u01c1"
            + "\u01bf\3\2\2\2\u01c1\u01c2\3\2\2\2\u01c2\u01c4\3\2\2\2\u01c3\u01c1\3\2"
            + "\2\2\u01c4\u01eb\7X\2\2\u01c5\u01c6\6\37\20\2\u01c6\u01c7\7W\2\2\u01c7"
            + "\u01c8\7\24\2\2\u01c8\u01c9\5<\37\2\u01c9\u01ca\7X\2\2\u01ca\u01eb\3\2"
            + "\2\2\u01cb\u01cc\6\37\21\2\u01cc\u01cd\7W\2\2\u01cd\u01ce\7\25\2\2\u01ce"
            + "\u01cf\5<\37\2\u01cf\u01d0\5<\37\2\u01d0\u01d1\7X\2\2\u01d1\u01eb\3\2"
            + "\2\2\u01d2\u01d3\6\37\22\2\u01d3\u01d4\7W\2\2\u01d4\u01d5\7\26\2\2\u01d5"
            + "\u01d7\7W\2\2\u01d6\u01d8\5\"\22\2\u01d7\u01d6\3\2\2\2\u01d7\u01d8\3\2"
            + "\2\2\u01d8\u01d9\3\2\2\2\u01d9\u01da\7X\2\2\u01da\u01db\5<\37\2\u01db"
            + "\u01dc\7X\2\2\u01dc\u01eb\3\2\2\2\u01dd\u01de\6\37\23\2\u01de\u01df\7"
            + "W\2\2\u01df\u01e0\7\27\2\2\u01e0\u01e2\7W\2\2\u01e1\u01e3\5\"\22\2\u01e2"
            + "\u01e1\3\2\2\2\u01e2\u01e3\3\2\2\2\u01e3\u01e4\3\2\2\2\u01e4\u01e5\7X"
            + "\2\2\u01e5\u01e6\5<\37\2\u01e6\u01e7\7X\2\2\u01e7\u01eb\3\2\2\2\u01e8"
            + "\u01e9\6\37\24\2\u01e9\u01eb\5> \2\u01ea\u01af\3\2\2\2\u01ea\u01b0\3\2"
            + "\2\2\u01ea\u01b2\3\2\2\2\u01ea\u01bb\3\2\2\2\u01ea\u01c5\3\2\2\2\u01ea"
            + "\u01cb\3\2\2\2\u01ea\u01d2\3\2\2\2\u01ea\u01dd\3\2\2\2\u01ea\u01e8\3\2"
            + "\2\2\u01eb=\3\2\2\2\u01ec\u01ed\7W\2\2\u01ed\u01ee\5T+\2\u01ee\u01ef\5"
            + "L\'\2\u01ef\u01f0\5L\'\2\u01f0\u01f1\7X\2\2\u01f1?\3\2\2\2\u01f2\u01f9"
            + "\5D#\2\u01f3\u01f4\7W\2\2\u01f4\u01f5\7\24\2\2\u01f5\u01f6\5D#\2\u01f6"
            + "\u01f7\7X\2\2\u01f7\u01f9\3\2\2\2\u01f8\u01f2\3\2\2\2\u01f8\u01f3\3\2"
            + "\2\2\u01f9A\3\2\2\2\u01fa\u0201\5F$\2\u01fb\u01fc\7W\2\2\u01fc\u01fd\7"
            + "\24\2\2\u01fd\u01fe\5F$\2\u01fe\u01ff\7X\2\2\u01ff\u0201\3\2\2\2\u0200"
            + "\u01fa\3\2\2\2\u0200\u01fb\3\2\2\2\u0201C\3\2\2\2\u0202\u0203\7W\2\2\u0203"
            + "\u0207\5\16\b\2\u0204\u0206\5H%\2\u0205\u0204\3\2\2\2\u0206\u0209\3\2"
            + "\2\2\u0207\u0205\3\2\2\2\u0207\u0208\3\2\2\2\u0208\u020a\3\2\2\2\u0209"
            + "\u0207\3\2\2\2\u020a\u020b\7X\2\2\u020b\u0214\3\2\2\2\u020c\u020d\6#\25"
            + "\2\u020d\u020e\7W\2\2\u020e\u020f\7]\2\2\u020f\u0210\5H%\2\u0210\u0211"
            + "\5H%\2\u0211\u0212\7X\2\2\u0212\u0214\3\2\2\2\u0213\u0202\3\2\2\2\u0213"
            + "\u020c\3\2\2\2\u0214E\3\2\2\2\u0215\u0216\7W\2\2\u0216\u021a\5\16\b\2"
            + "\u0217\u0219\5V,\2\u0218\u0217\3\2\2\2\u0219\u021c\3\2\2\2\u021a\u0218"
            + "\3\2\2\2\u021a\u021b\3\2\2\2\u021b\u021d\3\2\2\2\u021c\u021a\3\2\2\2\u021d"
            + "\u021e\7X\2\2\u021e\u0227\3\2\2\2\u021f\u0220\6$\26\2\u0220\u0221\7W\2"
            + "\2\u0221\u0222\7]\2\2\u0222\u0223\5V,\2\u0223\u0224\5V,\2\u0224\u0225"
            + "\7X\2\2\u0225\u0227\3\2\2\2\u0226\u0215\3\2\2\2\u0226\u021f\3\2\2\2\u0227"
            + "G\3\2\2\2\u0228\u022d\5V,\2\u0229\u022d\5\20\t\2\u022a\u022b\6%\27\2\u022b"
            + "\u022d\5J&\2\u022c\u0228\3\2\2\2\u022c\u0229\3\2\2\2\u022c\u022a\3\2\2"
            + "\2\u022dI\3\2\2\2\u022e\u022f\6&\30\2\u022f\u0230\7W\2\2\u0230\u0234\5"
            + "\24\13\2\u0231\u0233\5H%\2\u0232\u0231\3\2\2\2\u0233\u0236\3\2\2\2\u0234"
            + "\u0232\3\2\2\2\u0234\u0235\3\2\2\2\u0235\u0237\3\2\2\2\u0236\u0234\3\2"
            + "\2\2\u0237\u0238\7X\2\2\u0238K\3\2\2\2\u0239\u023a\6\'\31\2\u023a\u0256"
            + "\7c\2\2\u023b\u023c\6\'\32\2\u023c\u023d\7W\2\2\u023d\u023e\5P)\2\u023e"
            + "\u023f\5L\'\2\u023f\u0240\5L\'\2\u0240\u0241\7X\2\2\u0241\u0256\3\2\2"
            + "\2\u0242\u0243\6\'\33\2\u0243\u0244\7W\2\2\u0244\u0245\5R*\2\u0245\u0247"
            + "\5L\'\2\u0246\u0248\5L\'\2\u0247\u0246\3\2\2\2\u0248\u0249\3\2\2\2\u0249"
            + "\u0247\3\2\2\2\u0249\u024a\3\2\2\2\u024a\u024b\3\2\2\2\u024b\u024c\7X"
            + "\2\2\u024c\u0256\3\2\2\2\u024d\u024e\6\'\34\2\u024e\u024f\7W\2\2\u024f"
            + "\u0250\7Z\2\2\u0250\u0251\5L\'\2\u0251\u0252\7X\2\2\u0252\u0256\3\2\2"
            + "\2\u0253\u0254\6\'\35\2\u0254\u0256\5N(\2\u0255\u0239\3\2\2\2\u0255\u023b"
            + "\3\2\2\2\u0255\u0242\3\2\2\2\u0255\u024d\3\2\2\2\u0255\u0253\3\2\2\2\u0256"
            + "M\3\2\2\2\u0257\u0258\7W\2\2\u0258\u025c\5\24\13\2\u0259\u025b\5H%\2\u025a"
            + "\u0259\3\2\2\2\u025b\u025e\3\2\2\2\u025c\u025a\3\2\2\2\u025c\u025d\3\2"
            + "\2\2\u025d\u025f\3\2\2\2\u025e\u025c\3\2\2\2\u025f\u0260\7X\2\2\u0260"
            + "\u0263\3\2\2\2\u0261\u0263\5\24\13\2\u0262\u0257\3\2\2\2\u0262\u0261\3"
            + "\2\2\2\u0263O\3\2\2\2\u0264\u0267\5R*\2\u0265\u0267\t\2\2\2\u0266\u0264"
            + "\3\2\2\2\u0266\u0265\3\2\2\2\u0267Q\3\2\2\2\u0268\u0269\t\3\2\2\u0269"
            + "S\3\2\2\2\u026a\u026b\t\4\2\2\u026bU\3\2\2\2\u026c\u026d\t\5\2\2\u026d"
            + "W\3\2\2\2\u026e\u026f\7W\2\2\u026f\u0273\7\22\2\2\u0270\u0272\5Z.\2\u0271"
            + "\u0270\3\2\2\2\u0272\u0275\3\2\2\2\u0273\u0271\3\2\2\2\u0273\u0274\3\2"
            + "\2\2\u0274\u0276\3\2\2\2\u0275\u0273\3\2\2\2\u0276\u0279\7X\2\2\u0277"
            + "\u0279\5Z.\2\u0278\u026e\3\2\2\2\u0278\u0277\3\2\2\2\u0279Y\3\2\2\2\u027a"
            + "\u027b\6.\36\2\u027b\u027c\7W\2\2\u027c\u027d\7\27\2\2\u027d\u027f\7W"
            + "\2\2\u027e\u0280\5\"\22\2\u027f\u027e\3\2\2\2\u027f\u0280\3\2\2\2\u0280"
            + "\u0281\3\2\2\2\u0281\u0282\7X\2\2\u0282\u0283\5X-\2\u0283\u0284\7X\2\2"
            + "\u0284\u028e\3\2\2\2\u0285\u0286\6.\37\2\u0286\u0287\7W\2\2\u0287\u0288"
            + "\7\31\2\2\u0288\u0289\5<\37\2\u0289\u028a\5^\60\2\u028a\u028b\7X\2\2\u028b"
            + "\u028e\3\2\2\2\u028c\u028e\5\\/\2\u028d\u027a\3\2\2\2\u028d\u0285\3\2"
            + "\2\2\u028d\u028c\3\2\2\2\u028e[\3\2\2\2\u028f\u0290\7W\2\2\u0290\u0291"
            + "\7\24\2\2\u0291\u0292\5D#\2\u0292\u0293\7X\2\2\u0293\u02ab\3\2\2\2\u0294"
            + "\u02ab\5D#\2\u0295\u0296\6/ \2\u0296\u0297\7W\2\2\u0297\u0298\5`\61\2"
            + "\u0298\u0299\5N(\2\u0299\u029a\5L\'\2\u029a\u029b\7X\2\2\u029b\u02ab\3"
            + "\2\2\2\u029c\u029d\6/!\2\u029d\u029e\7W\2\2\u029e\u029f\7\32\2\2\u029f"
            + "\u02a0\5J&\2\u02a0\u02a1\5H%\2\u02a1\u02a2\7X\2\2\u02a2\u02ab\3\2\2\2"
            + "\u02a3\u02a4\6/\"\2\u02a4\u02a5\7W\2\2\u02a5\u02a6\7\32\2\2\u02a6\u02a7"
            + "\5J&\2\u02a7\u02a8\7\33\2\2\u02a8\u02a9\7X\2\2\u02a9\u02ab\3\2\2\2\u02aa"
            + "\u028f\3\2\2\2\u02aa\u0294\3\2\2\2\u02aa\u0295\3\2\2\2\u02aa\u029c\3\2"
            + "\2\2\u02aa\u02a3\3\2\2\2\u02ab]\3\2\2\2\u02ac\u02ad\7W\2\2\u02ad\u02b1"
            + "\7\22\2\2\u02ae\u02b0\5\\/\2\u02af\u02ae\3\2\2\2\u02b0\u02b3\3\2\2\2\u02b1"
            + "\u02af\3\2\2\2\u02b1\u02b2\3\2\2\2\u02b2\u02b4\3\2\2\2\u02b3\u02b1\3\2"
            + "\2\2\u02b4\u02b7\7X\2\2\u02b5\u02b7\5\\/\2\u02b6\u02ac\3\2\2\2\u02b6\u02b5"
            + "\3\2\2\2\u02b7_\3\2\2\2\u02b8\u02b9\t\6\2\2\u02b9a\3\2\2\2\u02ba\u02bb"
            + "\7W\2\2\u02bb\u02bc\7 \2\2\u02bc\u02bd\5d\63\2\u02bd\u02be\7\17\2\2\u02be"
            + "\u02c0\7W\2\2\u02bf\u02c1\5\"\22\2\u02c0\u02bf\3\2\2\2\u02c0\u02c1\3\2"
            + "\2\2\u02c1\u02c2\3\2\2\2\u02c2\u02c3\7X\2\2\u02c3\u02c4\5f\64\2\u02c4"
            + "\u02c5\7X\2\2\u02c5c\3\2\2\2\u02c6\u02c7\5V,\2\u02c7e\3\2\2\2\u02c8\u02c9"
            + "\7!\2\2\u02c9\u02ca\5r:\2\u02ca\u02cb\7\"\2\2\u02cb\u02cc\5,\27\2\u02cc"
            + "\u02cd\7\21\2\2\u02cd\u02ce\5.\30\2\u02ceg\3\2\2\2\u02cf\u02e5\5j\66\2"
            + "\u02d0\u02d1\7W\2\2\u02d1\u02d5\7\22\2\2\u02d2\u02d4\5h\65\2\u02d3\u02d2"
            + "\3\2\2\2\u02d4\u02d7\3\2\2\2\u02d5\u02d3\3\2\2\2\u02d5\u02d6\3\2\2\2\u02d6"
            + "\u02d8\3\2\2\2\u02d7\u02d5\3\2\2\2\u02d8\u02e5\7X\2\2\u02d9\u02da\6\65"
            + "#\2\u02da\u02db\7W\2\2\u02db\u02dc\7\27\2\2\u02dc\u02de\7W\2\2\u02dd\u02df"
            + "\5\"\22\2\u02de\u02dd\3\2\2\2\u02de\u02df\3\2\2\2\u02df\u02e0\3\2\2\2"
            + "\u02e0\u02e1\7X\2\2\u02e1\u02e2\5h\65\2\u02e2\u02e3\7X\2\2\u02e3\u02e5"
            + "\3\2\2\2\u02e4\u02cf\3\2\2\2\u02e4\u02d0\3\2\2\2\u02e4\u02d9\3\2\2\2\u02e5"
            + "i\3\2\2\2\u02e6\u02f1\5l\67\2\u02e7\u02e8\6\66$\2\u02e8\u02e9\7W\2\2\u02e9"
            + "\u02eb\7\30\2\2\u02ea\u02ec\5:\36\2\u02eb\u02ea\3\2\2\2\u02eb\u02ec\3"
            + "\2\2\2\u02ec\u02ed\3\2\2\2\u02ed\u02ee\5l\67\2\u02ee\u02ef\7X\2\2\u02ef"
            + "\u02f1\3\2\2\2\u02f0\u02e6\3\2\2\2\u02f0\u02e7\3\2\2\2\u02f1k\3\2\2\2"
            + "\u02f2\u02f3\7W\2\2\u02f3\u02f4\7#\2\2\u02f4\u02f5\5n8\2\u02f5\u02f6\5"
            + "<\37\2\u02f6\u02f7\7X\2\2\u02f7\u02ff\3\2\2\2\u02f8\u02f9\7W\2\2\u02f9"
            + "\u02fa\7$\2\2\u02fa\u02fb\5p9\2\u02fb\u02fc\5<\37\2\u02fc\u02fd\7X\2\2"
            + "\u02fd\u02ff\3\2\2\2\u02fe\u02f2\3\2\2\2\u02fe\u02f8\3\2\2\2\u02ffm\3"
            + "\2\2\2\u0300\u0301\t\7\2\2\u0301o\3\2\2\2\u0302\u0303\7\'\2\2\u0303q\3"
            + "\2\2\2\u0304\u0305\6:%\2\u0305\u0306\7W\2\2\u0306\u0308\7\22\2\2\u0307"
            + "\u0309\5t;\2\u0308\u0307\3\2\2\2\u0309\u030a\3\2\2\2\u030a\u0308\3\2\2"
            + "\2\u030a\u030b\3\2\2\2\u030b\u030c\3\2\2\2\u030c\u030d\7X\2\2\u030d\u0312"
            + "\3\2\2\2\u030e\u030f\7W\2\2\u030f\u0312\7X\2\2\u0310\u0312\5t;\2\u0311"
            + "\u0304\3\2\2\2\u0311\u030e\3\2\2\2\u0311\u0310\3\2\2\2\u0312s\3\2\2\2"
            + "\u0313\u0314\7W\2\2\u0314\u0315\5v<\2\u0315\u0316\7(\2\2\u0316\u0317\5"
            + "x=\2\u0317\u0318\7X\2\2\u0318\u0320\3\2\2\2\u0319\u031a\7W\2\2\u031a\u031b"
            + "\7#\2\2\u031b\u031c\5n8\2\u031c\u031d\5t;\2\u031d\u031e\7X\2\2\u031e\u0320"
            + "\3\2\2\2\u031f\u0313\3\2\2\2\u031f\u0319\3\2\2\2\u0320u\3\2\2\2\u0321"
            + "\u0322\6<&\2\u0322\u0327\7`\2\2\u0323\u0324\6<\'\2\u0324\u0327\7a\2\2"
            + "\u0325\u0327\7]\2\2\u0326\u0321\3\2\2\2\u0326\u0323\3\2\2\2\u0326\u0325"
            + "\3\2\2\2\u0327w\3\2\2\2\u0328\u032c\7c\2\2\u0329\u032a\6=(\2\u032a\u032c"
            + "\5L\'\2\u032b\u0328\3\2\2\2\u032b\u0329\3\2\2\2\u032cy\3\2\2\2\u032d\u032e"
            + "\7W\2\2\u032e\u0332\7\22\2\2\u032f\u0331\5z>\2\u0330\u032f\3\2\2\2\u0331"
            + "\u0334\3\2\2\2\u0332\u0330\3\2\2\2\u0332\u0333\3\2\2\2\u0333\u0335\3\2"
            + "\2\2\u0334\u0332\3\2\2\2\u0335\u034a\7X\2\2\u0336\u034a\5|?\2\u0337\u0338"
            + "\6>)\2\u0338\u0339\7W\2\2\u0339\u033a\7\27\2\2\u033a\u033c\7W\2\2\u033b"
            + "\u033d\5\"\22\2\u033c\u033b\3\2\2\2\u033c\u033d\3\2\2\2\u033d\u033e\3"
            + "\2\2\2\u033e\u033f\7X\2\2\u033f\u0340\5z>\2\u0340\u0341\7X\2\2\u0341\u034a"
            + "\3\2\2\2\u0342\u0343\6>*\2\u0343\u0344\7W\2\2\u0344\u0345\7\31\2\2\u0345"
            + "\u0346\5h\65\2\u0346\u0347\5|?\2\u0347\u0348\7X\2\2\u0348\u034a\3\2\2"
            + "\2\u0349\u032d\3\2\2\2\u0349\u0336\3\2\2\2\u0349\u0337\3\2\2\2\u0349\u0342"
            + "\3\2\2\2\u034a{\3\2\2\2\u034b\u034c\7W\2\2\u034c\u034d\7#\2\2\u034d\u034e"
            + "\5n8\2\u034e\u034f\5^\60\2\u034f\u0350\7X\2\2\u0350\u0360\3\2\2\2\u0351"
            + "\u0352\6?+\2\u0352\u0353\7W\2\2\u0353\u0354\7#\2\2\u0354\u0355\5n8\2\u0355"
            + "\u0356\5~@\2\u0356\u0357\7X\2\2\u0357\u0360\3\2\2\2\u0358\u0359\6?,\2"
            + "\u0359\u035a\7W\2\2\u035a\u035b\5\u0082B\2\u035b\u035c\5N(\2\u035c\u035d"
            + "\5\u0084C\2\u035d\u035e\7X\2\2\u035e\u0360\3\2\2\2\u035f\u034b\3\2\2\2"
            + "\u035f\u0351\3\2\2\2\u035f\u0358\3\2\2\2\u0360}\3\2\2\2\u0361\u0362\7"
            + "W\2\2\u0362\u0363\5`\61\2\u0363\u0364\5N(\2\u0364\u0365\5\u0080A\2\u0365"
            + "\u0366\7X\2\2\u0366\177\3\2\2\2\u0367\u0368\7W\2\2\u0368\u0369\5P)\2\u0369"
            + "\u036a\5\u0080A\2\u036a\u036b\5\u0080A\2\u036b\u036c\7X\2\2\u036c\u0380"
            + "\3\2\2\2\u036d\u036e\7W\2\2\u036e\u036f\5R*\2\u036f\u0371\5\u0080A\2\u0370"
            + "\u0372\5\u0080A\2\u0371\u0370\3\2\2\2\u0372\u0373\3\2\2\2\u0373\u0371"
            + "\3\2\2\2\u0373\u0374\3\2\2\2\u0374\u0375\3\2\2\2\u0375\u0376\7X\2\2\u0376"
            + "\u0380\3\2\2\2\u0377\u0378\7W\2\2\u0378\u0379\7Z\2\2\u0379\u037a\5\u0080"
            + "A\2\u037a\u037b\7X\2\2\u037b\u0380\3\2\2\2\u037c\u037d\6A-\2\u037d\u0380"
            + "\7(\2\2\u037e\u0380\5L\'\2\u037f\u0367\3\2\2\2\u037f\u036d\3\2\2\2\u037f"
            + "\u0377\3\2\2\2\u037f\u037c\3\2\2\2\u037f\u037e\3\2\2\2\u0380\u0081\3\2"
            + "\2\2\u0381\u0382\t\b\2\2\u0382\u0083\3\2\2\2\u0383\u0384\7W\2\2\u0384"
            + "\u0385\7[\2\2\u0385\u0386\5L\'\2\u0386\u0387\7)\2\2\u0387\u0388\7X\2\2"
            + "\u0388\u0391\3\2\2\2\u0389\u038a\7W\2\2\u038a\u038b\7[\2\2\u038b\u038c"
            + "\7)\2\2\u038c\u038d\5L\'\2\u038d\u038e\7X\2\2\u038e\u0391\3\2\2\2\u038f"
            + "\u0391\7)\2\2\u0390\u0383\3\2\2\2\u0390\u0389\3\2\2\2\u0390\u038f\3\2"
            + "\2\2\u0391\u0085\3\2\2\2\u0392\u0393\7W\2\2\u0393\u0394\7*\2\2\u0394\u0395"
            + "\5\f\7\2\u0395\u0396\5<\37\2\u0396\u0397\7X\2\2\u0397\u0087\3\2\2\2\u0398"
            + "\u0399\7W\2\2\u0399\u039a\7\3\2\2\u039a\u039b\7W\2\2\u039b\u039c\7+\2"
            + "\2\u039c\u039d\5V,\2\u039d\u039e\7X\2\2\u039e\u039f\7W\2\2\u039f\u03a0"
            + "\7,\2\2\u03a0\u03a1\5V,\2\u03a1\u03a3\7X\2\2\u03a2\u03a4\5\4\3\2\u03a3"
            + "\u03a2\3\2\2\2\u03a3\u03a4\3\2\2\2\u03a4\u03a6\3\2\2\2\u03a5\u03a7\5\u008a"
            + "F\2\u03a6\u03a5\3\2\2\2\u03a6\u03a7\3\2\2\2\u03a7\u03a8\3\2\2\2\u03a8"
            + "\u03a9\5\u008cG\2\u03a9\u03ab\5\u0092J\2\u03aa\u03ac\5\34\17\2\u03ab\u03aa"
            + "\3\2\2\2\u03ab\u03ac\3\2\2\2\u03ac\u03ae\3\2\2\2\u03ad\u03af\5\u0098M"
            + "\2\u03ae\u03ad\3\2\2\2\u03ae\u03af\3\2\2\2\u03af\u03b1\3\2\2\2\u03b0\u03b2"
            + "\5\u009eP\2\u03b1\u03b0\3\2\2\2\u03b1\u03b2\3\2\2\2\u03b2\u03b3\3\2\2"
            + "\2\u03b3\u03b4\7X\2\2\u03b4\u0089\3\2\2\2\u03b5\u03b6\7W\2\2\u03b6\u03b8"
            + "\7-\2\2\u03b7\u03b9\5 \21\2\u03b8\u03b7\3\2\2\2\u03b8\u03b9\3\2\2\2\u03b9"
            + "\u03ba\3\2\2\2\u03ba\u03bb\7X\2\2\u03bb\u008b\3\2\2\2\u03bc\u03bd\7W\2"
            + "\2\u03bd\u03c1\7.\2\2\u03be\u03c0\5\u008eH\2\u03bf\u03be\3\2\2\2\u03c0"
            + "\u03c3\3\2\2\2\u03c1\u03bf\3\2\2\2\u03c1\u03c2\3\2\2\2\u03c2\u03c4\3\2"
            + "\2\2\u03c3\u03c1\3\2\2\2\u03c4\u03c5\7X\2\2\u03c5\u008d\3\2\2\2\u03c6"
            + "\u03dd\5B\"\2\u03c7\u03c8\6H.\2\u03c8\u03c9\7W\2\2\u03c9\u03ca\7#\2\2"
            + "\u03ca\u03cb\7c\2\2\u03cb\u03cc\5B\"\2\u03cc\u03cd\7X\2\2\u03cd\u03dd"
            + "\3\2\2\2\u03ce\u03cf\6H/\2\u03cf\u03d0\7W\2\2\u03d0\u03d1\7]\2\2\u03d1"
            + "\u03d2\5\u0090I\2\u03d2\u03d3\7c\2\2\u03d3\u03d4\7X\2\2\u03d4\u03dd\3"
            + "\2\2\2\u03d5\u03d6\6H\60\2\u03d6\u03d7\7W\2\2\u03d7\u03d8\7]\2\2\u03d8"
            + "\u03d9\5\u0090I\2\u03d9\u03da\5V,\2\u03da\u03db\7X\2\2\u03db\u03dd\3\2"
            + "\2\2\u03dc\u03c6\3\2\2\2\u03dc\u03c7\3\2\2\2\u03dc\u03ce\3\2\2\2\u03dc"
            + "\u03d5\3\2\2\2\u03dd\u008f\3\2\2\2\u03de\u03ea\5\24\13\2\u03df\u03e0\7"
            + "W\2\2\u03e0\u03e4\5\24\13\2\u03e1\u03e3\5V,\2\u03e2\u03e1\3\2\2\2\u03e3"
            + "\u03e6\3\2\2\2\u03e4\u03e2\3\2\2\2\u03e4\u03e5\3\2\2\2\u03e5\u03e7\3\2"
            + "\2\2\u03e6\u03e4\3\2\2\2\u03e7\u03e8\7X\2\2\u03e8\u03ea\3\2\2\2\u03e9"
            + "\u03de\3\2\2\2\u03e9\u03df\3\2\2\2\u03ea\u0091\3\2\2\2\u03eb\u03ec\7W"
            + "\2\2\u03ec\u03ed\7/\2\2\u03ed\u03ee\5\66\34\2\u03ee\u03ef\7X\2\2\u03ef"
            + "\u0093\3\2\2\2\u03f0\u03f1\7W\2\2\u03f1\u03f5\7\22\2\2\u03f2\u03f4\5\u0094"
            + "K\2\u03f3\u03f2\3\2\2\2\u03f4\u03f7\3\2\2\2\u03f5\u03f3\3\2\2\2\u03f5"
            + "\u03f6\3\2\2\2\u03f6\u03f8\3\2\2\2\u03f7\u03f5\3\2\2\2\u03f8\u040f\7X"
            + "\2\2\u03f9\u03fa\6K\61\2\u03fa\u03fb\7W\2\2\u03fb\u03fc\7\27\2\2\u03fc"
            + "\u03fe\7W\2\2\u03fd\u03ff\5\"\22\2\u03fe\u03fd\3\2\2\2\u03fe\u03ff\3\2"
            + "\2\2\u03ff\u0400\3\2\2\2\u0400\u0401\7X\2\2\u0401\u0402\5\u0094K\2\u0402"
            + "\u0403\7X\2\2\u0403\u040f\3\2\2\2\u0404\u0405\6K\62\2\u0405\u0406\7W\2"
            + "\2\u0406\u0408\7\30\2\2\u0407\u0409\5:\36\2\u0408\u0407\3\2\2\2\u0408"
            + "\u0409\3\2\2\2\u0409\u040a\3\2\2\2\u040a\u040b\5\u0096L\2\u040b\u040c"
            + "\7X\2\2\u040c\u040f\3\2\2\2\u040d\u040f\5\u0096L\2\u040e\u03f0\3\2\2\2"
            + "\u040e\u03f9\3\2\2\2\u040e\u0404\3\2\2\2\u040e\u040d\3\2\2\2\u040f\u0095"
            + "\3\2\2\2\u0410\u0411\7W\2\2\u0411\u0415\7\22\2\2\u0412\u0414\5\u0096L"
            + "\2\u0413\u0412\3\2\2\2\u0414\u0417\3\2\2\2\u0415\u0413\3\2\2\2\u0415\u0416"
            + "\3\2\2\2\u0416\u0418\3\2\2\2\u0417\u0415\3\2\2\2\u0418\u045f\7X\2\2\u0419"
            + "\u041a\7W\2\2\u041a\u041b\7\27\2\2\u041b\u041d\7W\2\2\u041c\u041e\5\""
            + "\22\2\u041d\u041c\3\2\2\2\u041d\u041e\3\2\2\2\u041e\u041f\3\2\2\2\u041f"
            + "\u0420\7X\2\2\u0420\u0421\5\u0096L\2\u0421\u0422\7X\2\2\u0422\u045f\3"
            + "\2\2\2\u0423\u0424\7W\2\2\u0424\u0425\7#\2\2\u0425\u0426\7&\2\2\u0426"
            + "\u0427\5<\37\2\u0427\u0428\7X\2\2\u0428\u045f\3\2\2\2\u0429\u042a\7W\2"
            + "\2\u042a\u042b\7\60\2\2\u042b\u042c\5<\37\2\u042c\u042d\7X\2\2\u042d\u045f"
            + "\3\2\2\2\u042e\u042f\7W\2\2\u042f\u0430\7\61\2\2\u0430\u0431\5<\37\2\u0431"
            + "\u0432\7X\2\2\u0432\u045f\3\2\2\2\u0433\u0434\7W\2\2\u0434\u0435\7\62"
            + "\2\2\u0435\u0436\7c\2\2\u0436\u0437\5<\37\2\u0437\u0438\7X\2\2\u0438\u045f"
            + "\3\2\2\2\u0439\u043a\7W\2\2\u043a\u043b\7\63\2\2\u043b\u043c\5<\37\2\u043c"
            + "\u043d\7X\2\2\u043d\u045f\3\2\2\2\u043e\u043f\7W\2\2\u043f\u0440\7\64"
            + "\2\2\u0440\u0441\5<\37\2\u0441\u0442\5<\37\2\u0442\u0443\7X\2\2\u0443"
            + "\u045f\3\2\2\2\u0444\u0445\7W\2\2\u0445\u0446\7\65\2\2\u0446\u0447\5<"
            + "\37\2\u0447\u0448\5<\37\2\u0448\u0449\7X\2\2\u0449\u045f\3\2\2\2\u044a"
            + "\u044b\7W\2\2\u044b\u044c\7\66\2\2\u044c\u044d\7c\2\2\u044d\u044e\5<\37"
            + "\2\u044e\u044f\5<\37\2\u044f\u0450\7X\2\2\u0450\u045f\3\2\2\2\u0451\u0452"
            + "\7W\2\2\u0452\u0453\7\67\2\2\u0453\u0454\7c\2\2\u0454\u0455\7c\2\2\u0455"
            + "\u0456\5<\37\2\u0456\u0457\7X\2\2\u0457\u045f\3\2\2\2\u0458\u0459\7W\2"
            + "\2\u0459\u045a\78\2\2\u045a\u045b\7c\2\2\u045b\u045c\5<\37\2\u045c\u045d"
            + "\7X\2\2\u045d\u045f\3\2\2\2\u045e\u0410\3\2\2\2\u045e\u0419\3\2\2\2\u045e"
            + "\u0423\3\2\2\2\u045e\u0429\3\2\2\2\u045e\u042e\3\2\2\2\u045e\u0433\3\2"
            + "\2\2\u045e\u0439\3\2\2\2\u045e\u043e\3\2\2\2\u045e\u0444\3\2\2\2\u045e"
            + "\u044a\3\2\2\2\u045e\u0451\3\2\2\2\u045e\u0458\3\2\2\2\u045f\u0097\3\2"
            + "\2\2\u0460\u0461\6M\63\2\u0461\u0462\7W\2\2\u0462\u0463\79\2\2\u0463\u0464"
            + "\5\u009aN\2\u0464\u0465\5\u009cO\2\u0465\u0466\7X\2\2\u0466\u0099\3\2"
            + "\2\2\u0467\u0468\t\t\2\2\u0468\u009b\3\2\2\2\u0469\u046a\7W\2\2\u046a"
            + "\u046b\5P)\2\u046b\u046c\5\u009cO\2\u046c\u046d\5\u009cO\2\u046d\u046e"
            + "\7X\2\2\u046e\u0494\3\2\2\2\u046f\u0470\7W\2\2\u0470\u0471\5R*\2\u0471"
            + "\u0473\5\u009cO\2\u0472\u0474\5\u009cO\2\u0473\u0472\3\2\2\2\u0474\u0475"
            + "\3\2\2\2\u0475\u0473\3\2\2\2\u0475\u0476\3\2\2\2\u0476\u0477\3\2\2\2\u0477"
            + "\u0478\7X\2\2\u0478\u0494\3\2\2\2\u0479\u047a\7W\2\2\u047a\u047b\7Z\2"
            + "\2\u047b\u047c\5\u009cO\2\u047c\u047d\7X\2\2\u047d\u0494\3\2\2\2\u047e"
            + "\u0494\7c\2\2\u047f\u0480\7W\2\2\u0480\u0484\5\24\13\2\u0481\u0483\5V"
            + ",\2\u0482\u0481\3\2\2\2\u0483\u0486\3\2\2\2\u0484\u0482\3\2\2\2\u0484"
            + "\u0485\3\2\2\2\u0485\u0487\3\2\2\2\u0486\u0484\3\2\2\2\u0487\u0488\7X"
            + "\2\2\u0488\u0494\3\2\2\2\u0489\u0494\5\24\13\2\u048a\u048b\7W\2\2\u048b"
            + "\u048c\7<\2\2\u048c\u0494\7X\2\2\u048d\u048e\6O\64\2\u048e\u048f\7W\2"
            + "\2\u048f\u0490\7=\2\2\u0490\u0491\5:\36\2\u0491\u0492\7X\2\2\u0492\u0494"
            + "\3\2\2\2\u0493\u0469\3\2\2\2\u0493\u046f\3\2\2\2\u0493\u0479\3\2\2\2\u0493"
            + "\u047e\3\2\2\2\u0493\u047f\3\2\2\2\u0493\u0489\3\2\2\2\u0493\u048a\3\2"
            + "\2\2\u0493\u048d\3\2\2\2\u0494\u009d\3\2\2\2\u0495\u0496\7W\2\2\u0496"
            + "\u049b\7>\2\2\u0497\u0498\7W\2\2\u0498\u0499\7?\2\2\u0499\u049a\7c\2\2"
            + "\u049a\u049c\7X\2\2\u049b\u0497\3\2\2\2\u049b\u049c\3\2\2\2\u049c\u04a1"
            + "\3\2\2\2\u049d\u049e\7W\2\2\u049e\u049f\7@\2\2\u049f\u04a0\7c\2\2\u04a0"
            + "\u04a2\7X\2\2\u04a1\u049d\3\2\2\2\u04a1\u04a2\3\2\2\2\u04a2\u04a3\3\2"
            + "\2\2\u04a3\u04a4\7X\2\2\u04a4\u009f\3\2\2\2\u04a5\u04a6\t\n\2\2\u04a6"
            + "\u00a1\3\2\2\2p\u00a9\u00ac\u00af\u00b2\u00b5\u00b8\u00bd\u00c7\u00ce"
            + "\u00d5\u00de\u00e5\u00f1\u00fb\u0103\u0108\u010d\u010f\u0115\u0123\u012a"
            + "\u012f\u0135\u013a\u013c\u0141\u0147\u014c\u014e\u0152\u0159\u015e\u0163"
            + "\u0168\u016d\u0172\u017a\u0184\u0188\u0190\u0199\u019f\u01a5\u01ab\u01b7"
            + "\u01c1\u01d7\u01e2\u01ea\u01f8\u0200\u0207\u0213\u021a\u0226\u022c\u0234"
            + "\u0249\u0255\u025c\u0262\u0266\u0273\u0278\u027f\u028d\u02aa\u02b1\u02b6"
            + "\u02c0\u02d5\u02de\u02e4\u02eb\u02f0\u02fe\u030a\u0311\u031f\u0326\u032b"
            + "\u0332\u033c\u0349\u035f\u0373\u037f\u0390\u03a3\u03a6\u03ab\u03ae\u03b1"
            + "\u03b8\u03c1\u03dc\u03e4\u03e9\u03f5\u03fe\u0408\u040e\u0415\u041d\u045e"
            + "\u0475\u0484\u0493\u049b\u04a1";
    public static final ATN _ATN
            = new ATNDeserializer().deserialize(_serializedATN.toCharArray());

    static {
        _decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
        for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
            _decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
        }
    }
}
