grammar PDDL;

@lexer::members {final java.util.Set<String> requirements = new java.util.HashSet<>();}

@parser::members {final java.util.Set<String> requirements = new java.util.HashSet<>();}

domain
    :   '(' 'define' '(' 'domain' name ')' require_def? types_def? constants_def? predicates_def? functions_def? constraints? structure_def* ')';

require_def
    :   '(' ':requirements' require_key+ ')';

types_def
    :   '(' ':types' typed_list_name? ')';

constants_def
    :   '(' ':constants' typed_list_name? ')';

predicates_def
    :   '(' ':predicates' atomic_formula_skeleton+ ')';

atomic_formula_skeleton
    :   '(' predicate typed_list_variable? ')';

predicate
    :   name;

variable
    :   '?' name;

atomic_function_skeleton
    :   '(' function_symbol typed_list_variable? ')';

function_symbol
    :   name;

functions_def
    :   {requirements.contains(":fluents") || requirements.contains(":numeric-fluents") || requirements.contains(":object-fluents")}? '(' ':functions' function_typed_list_atomic_function_skeleton? ')';

function_typed_list_atomic_function_skeleton
    :   {requirements.contains(":numeric-fluents")}? atomic_function_skeleton+
    |   atomic_function_skeleton+ '-' function_type function_typed_list_atomic_function_skeleton?;

function_type
    :   {requirements.contains(":numeric-fluents")}? 'number'
    |   {requirements.contains(":typing") && requirements.contains(":object-fluents")}? type;

constraints
    :   {requirements.contains(":constraints")}? '(' ':constraints' con_GD ')'
    |   {requirements.contains(":constraints")}? '(' ':constraints' pref_con_GD ')';

structure_def
    :   action_def
    |   {requirements.contains(":durative-actions")}? durative_action_def
    |   {requirements.contains(":derived-predicates")}? derived_def;

typed_list_name
    :   name+
    |   {requirements.contains(":typing")}? name+ '-' type typed_list_name?;

typed_list_variable
    :   variable+
    |   {requirements.contains(":typing")}? variable+ '-' type typed_list_variable?;

primitive_type
    :   name
    |   'object';

type
    :   '(' 'either' primitive_type+ ')'
    |   primitive_type;

emptyOr_pre_GD
    :   '(' ')'
    |   pre_GD;

emptyOr_effect
    :   '(' ')'
    |   effect;

emptyOr_da_GD
    :   '(' ')'
    |   da_GD;

emptyOr_da_effect
    :   '(' ')'
    |   da_effect;

action_def
    :   '(' ':action' action_symbol ':parameters' '(' typed_list_variable? ')' action_def_body ')';

action_symbol
    :   name;

action_def_body
    :   (':precondition' emptyOr_pre_GD)? (':effect' emptyOr_effect)?;

pre_GD
    :   pref_GD                                                                                                     #pre_GD_pref_GD
    |   '(' 'and' pre_GD* ')'                                                                                       #pre_GD_and
    |   {requirements.contains(":universal-preconditions")}? '(' 'forall' '(' typed_list_variable? ')' pre_GD ')'   #pre_GD_forall;

pref_GD
    :   {requirements.contains(":preferences")}? '(' 'preference' pref_name? gD ')'                                 #pref_GD_preference_gD
    |   gD                                                                                                          #pref_GD_gD;

pref_name
    :   name;

gD
    :   atomic_formula_term                                                                                         #gd_atomic_formula_term
    |   {requirements.contains(":negative-preconditions")}? literal_term                                            #gd_literal_term
    |   '(' 'and' gD* ')'                                                                                           #gd_and
    |   {requirements.contains(":disjunctive-preconditions")}? '(' 'or' gD* ')'                                     #gd_or
    |   {requirements.contains(":disjunctive-preconditions")}? '(' 'not' gD ')'                                     #gd_not
    |   {requirements.contains(":disjunctive-preconditions")}? '(' 'imply' gD gD ')'                                #gd_imply
    |   {requirements.contains(":existential-preconditions")}? '(' 'exists' '(' typed_list_variable? ')' gD ')'     #gd_exists
    |   {requirements.contains(":universal-preconditions")}? '(' 'forall' '(' typed_list_variable? ')' gD ')'       #gd_forall
    |   {requirements.contains(":numeric-fluents")}? f_comp                                                         #gd_f_comp;

f_comp
    :   '(' binary_comp f_exp f_exp ')';

literal_term
    :   atomic_formula_term                                                                                         #literal_term_atomic_formula_term
    |   '(' 'not' atomic_formula_term ')'                                                                           #literal_term_not_atomic_formula_term;

literal_name
    :   atomic_formula_name                                                                                         #literal_name_atomic_formula_name
    |   '(' 'not' atomic_formula_name ')'                                                                           #literal_name_not_atomic_formula_name;

atomic_formula_term
    :   '(' predicate term* ')'                                                                                     #atomic_formula_term_predicate
    |   {requirements.contains(":equality")}? '(' '=' term term ')'                                                 #atomic_formula_term_eq;

atomic_formula_name
    :   '(' predicate name* ')'                                                                                     #atomic_formula_name_predicate
    |   {requirements.contains(":equality")}? '(' '=' name name ')'                                                 #atomic_formula_name_eq;

term
    :   name                                                                                                        #term_name
    |   variable                                                                                                    #term_variable
    |   {requirements.contains(":object-fluents")}? function_term                                                   #term_function;

function_term
    :   {requirements.contains(":object-fluents")}? '(' function_symbol term* ')';

f_exp
    :   {requirements.contains(":numeric-fluents")}? NUMBER                                                         #f_exp_number
    |   {requirements.contains(":numeric-fluents")}? '(' binary_op f_exp f_exp ')'                                  #f_exp_binary_op
    |   {requirements.contains(":numeric-fluents")}? '(' multi_op f_exp f_exp+ ')'                                  #f_exp_multi_op
    |   {requirements.contains(":numeric-fluents")}? '(' '-' f_exp ')'                                              #f_exp_minus
    |   {requirements.contains(":numeric-fluents")}? f_head                                                         #f_exp_f_head;

f_head
    :   '(' function_symbol term* ')'                                                                               #f_head_function_symbol_terms
    |   function_symbol                                                                                             #f_head_function_symbol;

binary_op
    :   multi_op
    |   ('-' | '/');

multi_op
    :   '*'
    |   '+';

binary_comp
    :   '>'
    |   '<'
    |   '='
    |   '>='
    |   '<=';

name
    :   NAME | 'at' | 'over'; // this is just terrible..

effect
    :   '(' 'and' c_effect* ')'                                                                                     #effect_and_c_effect
    |   c_effect                                                                                                    #effect_c_effect;

c_effect
    :   {requirements.contains(":conditional-effects")}? '(' 'forall' '(' typed_list_variable? ')' effect ')'       #c_effect_forall
    |   {requirements.contains(":conditional-effects")}? '(' 'when' gD cond_effect ')'                              #c_effect_when
    |   p_effect                                                                                                    #c_effect_p_effect;

p_effect
    :   '(' 'not' atomic_formula_term ')'                                                                           #p_effect_negated_atomic_formula_term
    |   atomic_formula_term                                                                                         #p_effect_directed_atomic_formula_term
    |   {requirements.contains(":numeric-fluents")}? '(' assign_op f_head f_exp ')'                                 #p_effect_assign_op_f_head_f_exp
    |   {requirements.contains(":object-fluents")}? '(' 'assign' function_term term ')'                             #p_effect_assign_term
    |   {requirements.contains(":object-fluents")}? '(' 'assign' function_term 'undefined' ')'                      #p_effect_assign_undefined;

cond_effect
    :   '(' 'and' p_effect* ')'                                                                                     #cond_effect_and_p_effect
    |   p_effect                                                                                                    #cond_effect_p_effect;

assign_op
    :   'assign'
    |   'scale-up'
    |   'scale-down'
    |   'increase'
    |   'decrease';

durative_action_def
    :   '(' ':durative-action' da_symbol ':parameters' '(' typed_list_variable? ')' da_def_body ')';

da_symbol
    :   name;

da_def_body
    :   ':duration' duration_constraint ':condition' emptyOr_da_GD ':effect' emptyOr_da_effect;

da_GD
    :   pref_timed_GD                                                                                               #da_GD_pref_timed_GD
    |   '(' 'and' da_GD* ')'                                                                                        #da_GD_and
    |   {requirements.contains(":universal-preconditions")}? '(' 'forall' '(' typed_list_variable? ')' da_GD ')'    #da_GD_forall;

pref_timed_GD
    :   timed_GD                                                                                                    #pref_timed_GD_timed_GD
    |   {requirements.contains(":preferences")}? '(' 'preference' pref_name? timed_GD ')'                           #pref_timed_GD_preference_timed_GD;

timed_GD
    :   '(' 'at' time_specifier gD ')'                                                                              #timed_GD_at_GD
    |   '(' 'over' interval gD ')'                                                                                  #timed_GD_over_GD;

time_specifier
    :   'start'
    |   'end';

interval
    :   'all';

duration_constraint
    :   {requirements.contains(":duration-inequalities")}? '(' 'and' simple_duration_constraint+ ')'                #duration_constraint_and
    |   '(' ')'                                                                                                     #duration_constraint_empty
    |   simple_duration_constraint                                                                                  #duration_constraint_duration_constraint;

simple_duration_constraint
    :   '(' d_op '?duration' d_value ')'                                                                            #simple_duration_constraint_d_op
    |   '(' 'at' time_specifier simple_duration_constraint ')'                                                      #simple_duration_constraint_at;

d_op
    :   {requirements.contains(":duration-inequalities")}? '<='
    |   {requirements.contains(":duration-inequalities")}? '>='
    |   '=';

d_value
    :   NUMBER                                                                                                      #d_value_number
    |   {requirements.contains(":numeric-fluents")}? f_exp                                                          #d_value_f_exp;

da_effect
    :   '(' 'and' da_effect* ')'                                                                                    #da_effect_and
    |   timed_effect                                                                                                #da_effect_timed_effect
    |   {requirements.contains(":conditional-effects")}? '(' 'forall' '(' typed_list_variable? ')' da_effect ')'    #da_effect_forall
    |   {requirements.contains(":conditional-effects")}? '(' 'when' da_GD timed_effect ')'                          #da_effect_when;

timed_effect
    :   '(' 'at' time_specifier cond_effect ')'                                                                     #timed_effect_cond_effect
    |   {requirements.contains(":numeric-fluents")}? '(' 'at' time_specifier f_assign_da ')'                        #timed_effect_f_assign_da
    |   {requirements.contains(":continuous-effects") && requirements.contains(":numeric-fluents")}? '(' assign_op_t f_head f_exp_t ')' #timed_effect_assign_op;

f_assign_da
    :   '(' assign_op f_head f_exp_da ')';

f_exp_da
    :   '(' binary_op f_exp_da f_exp_da ')'                                                                         #f_exp_da_binary
    |   '(' multi_op f_exp_da f_exp_da+ ')'                                                                         #f_exp_da_multi
    |   '(' '-' f_exp_da ')'                                                                                        #f_exp_da_minus
    |   {requirements.contains(":duration-inequalities")}? '?duration'                                              #f_exp_da_duration
    |   f_exp                                                                                                       #f_exp_da_f_exp;

assign_op_t
    :   'increase'
    |   'decrease';

f_exp_t
    :   '(' '*' f_exp '#t' ')'
    |   '(' '*' '#t' f_exp ')'
    |   '#t';

derived_def
    :   '(' ':derived' atomic_formula_skeleton gD ')';

problem
    :   '(' 'define' '(' 'problem' name ')' '(' ':domain' name ')' require_def? object_declaration? init goal constraints? metric_spec? length_spec? ')';

object_declaration
    :   '(' ':objects' typed_list_name? ')';

init
    :   '(' ':init' init_el* ')';

init_el
    :   literal_name                                                                                    #init_el_literal_name
    |   {requirements.contains(":timed-initial-literals")}? '(' 'at' NUMBER literal_name ')'            #init_el_at
    |   {requirements.contains(":numeric-fluents")}? '(' '=' basic_function_term NUMBER ')'             #init_el_eq_number
    |   {requirements.contains(":object-fluents")}? '(' '=' basic_function_term name ')'                #init_el_eq_name;

basic_function_term
    :   function_symbol                                                                                 #basic_function_term_function_symbol
    |   '(' function_symbol name* ')'                                                                   #basic_function_term_function_symbol_names;

goal
    :   '(' ':goal' pre_GD ')';

pref_con_GD
    :   '(' 'and' pref_con_GD* ')'                                                                      #pref_con_GD_and
    |   {requirements.contains(":universal-preconditions")}? '(' 'forall' '(' typed_list_variable? ')' pref_con_GD ')'  #pref_con_GD_forall
    |   {requirements.contains(":preferences")}? '(' 'preference' pref_name? con_GD ')'                 #pref_con_GD_preference
    |   con_GD                                                                                          #pref_con_GD_con_GD;

con_GD
    :   '(' 'and' con_GD* ')'                                                                           #con_GD_and
    |   '(' 'forall' '(' typed_list_variable? ')' con_GD ')'                                            #con_GD_forall
    |   '(' 'at' 'end' gD ')'                                                                           #con_GD_at_end
    |   '(' 'always' gD ')'                                                                             #con_GD_always
    |   '(' 'sometime' gD ')'                                                                           #con_GD_sometime
    |   '(' 'within' NUMBER gD ')'                                                                      #con_GD_within
    |   '(' 'at-most-once' gD ')'                                                                       #con_GD_at_most_once
    |   '(' 'sometime-after' gD gD ')'                                                                  #con_GD_sometime_after
    |   '(' 'sometime-before' gD gD ')'                                                                 #con_GD_sometime_before
    |   '(' 'always-within' NUMBER gD gD ')'                                                            #con_GD_always_within
    |   '(' 'hold-during' NUMBER NUMBER gD ')'                                                          #con_GD_hold_during
    |   '(' 'hold-after' NUMBER gD ')'                                                                  #con_GD_hold_after;

metric_spec
    :   {requirements.contains(":numeric-fluents")}? '(' ':metric' optimization metric_f_exp ')';

optimization
    :   'minimize'
    |   'maximize';

metric_f_exp
    :   '(' binary_op metric_f_exp metric_f_exp ')'                                                     #metric_f_exp_binary
    |   '(' multi_op metric_f_exp metric_f_exp+ ')'                                                     #metric_f_exp_multi
    |   '(' '-' metric_f_exp ')'                                                                        #metric_f_exp_minus
    |   NUMBER                                                                                          #metric_f_exp_number
    |   '(' function_symbol name* ')'                                                                   #metric_f_exp_function_symbol_name
    |   function_symbol                                                                                 #metric_f_exp_function_symbol
    |   '(' 'total-time' ')'                                                                            #metric_f_exp_total_time
    |   {requirements.contains(":preferences")}? '(' 'is-violated' pref_name ')'                        #metric_f_exp_is_violated;

length_spec
    :   '(' ':length' ('(' ':serial' NUMBER ')')? ('(' ':parallel' NUMBER ')')? ')';

require_key
    :   ':strips'
    |   ':typing'
    |   ':negative-preconditions'
    |   ':disjunctive-preconditions'
    |   ':equality'
    |   ':existential-preconditions'
    |   ':universal-preconditions'
    |   ':quantified-preconditions'
    |   ':conditional-effects'
    |   ':fluents'
    |   ':object-fluents'
    |   ':numeric-fluents'
    |   ':adl'
    |   ':durative-actions'
    |   ':duration-inequalities'
    |   ':continuous-effects'
    |   ':derived-predicates'
    |   ':timed-initial-literals'
    |   ':preferences'
    |   ':constraints'
    |   ':action-costs'
    |   ':goal-utilities';

DEFINE
    :   'define';

DOMAIN
    :   'domain';

REQUIREMENTS
    :   ':requirements';

TYPES
    :   ':types';

CONSTANTS
    :   ':constants';

PREDICATES
    :   ':predicates';

FUNCTIONS
    :   ':functions';

NUMBER_TYPE
    :   'number';

CONSTRAINTS
    :   ':constraints';

OBJECT_TYPE
    :   'object';

EITHER
    :   'either';

ACTION
    :   ':action';

PARAMETERS
    :   ':parameters';

PRECONDITION
    :   ':precondition';

EFFECT
    :   ':effect';

AND
    :   'and';

OR
    :   'or';

NOT
    :   'not';

IMPLY
    :   'imply';

EXISTS
    :   'exists';

FORALL
    :   'forall';

PREFERENCE
    :   'preference';

WHEN
    :   'when';

ASSIGN
    :   'assign';

UNDEFINED
    :   'undefined';

SCALE_UP
    :   'scale-up';

SCALE_DOWN
    :   'scale-down';

INCREASE
    :   'increase';

DECREASE
    :   'decrease';

DURATIVE_ACTION
    :   ':durative-action';

DURATION
    :   ':duration';

CONDITION
    :   ':condition';

AT
    :   'at';

OVER
    :   'over';

START
    :   'start';

END
    :   'end';

ALL
    :   'all';

DURATION_VARIABLE
    :   '?duration';

TIME
    :   '#t';

DERIVED
    :   ':derived';

PROBLEM
    :   'problem';

PROBLEM_DOMAIN
    :   ':domain';

OBJECTS
    :   ':objects';

INIT
    :   ':init';

GOAL
    :   ':goal';

ALWAYS
    :   'always';

SOMETIME
    :   'sometime';

WITHIN
    :   'within';

AT_MOST_ONCE
    :   'at-most-once';

SOMETIME_AFTER
    :   'sometime-after';

SOMETIME_BEFORE
    :   'sometime-before';

ALWAYS_WITHIN
    :   'always-within';

HOLD_DURING
    :   'hold-during';

HOLD_AFTER
    :   'hold-after';

METRIC
    :   ':metric';

MINIMIZE
    :   'minimize';

MAXIMIZE
    :   'maximize';

TOTAL_TIME
    :   'total-time';

IS_VIOLATED
    :   'is-violated';

LENGTH
    :   ':length';

SERIAL
    :   ':serial';

PARALLEL
    :   ':parallel';

STRIPS
    :   ':strips';

TYPING
    :   ':typing';

NEGATIVE_PRECONDITIONS
    :   ':negative-preconditions';

DISJUNCTIVE_PRECONDITIONS
    :   ':disjunctive-preconditions';

EQUALITY
    :   ':equality';

EXISTENTIAL_PRECONDITIONS
    :   ':existential-preconditions';

UNIVERSAL_PRECONDITIONS
    :   ':universal-preconditions';

QUANTIFIED_PRECONDITIONS
    :   ':quantified-preconditions';

CONDITIONAL_EFFECTS
    :   ':conditional-effects';

FLUENTS
    :   ':fluents';

NUMERIC_FLUENTS
    :   ':numeric-fluents';

OBJECT_FLUENTS
    :   ':object-fluents';

ADL
    :   ':adl';

DURATIVE_ACTIONS
    :   ':durative-actions';

DURATION_INEQUALITIES
    :   ':duration-inequalities';

CONTINUOUS_EFFECTS
    :   ':continuous-effects';

DERIVED_PREDICATES
    :   ':derived-predicates';

TIMED_INITIAL_LITERALS
    :   ':timed-initial-literals';

PREFERENCES
    :   ':preferences';

ACTION_COSTS
    :   ':action-costs';

GOAL_UTILITIES
    :   ':goal-utilities';

QUESTION
    :   '?';

LPAREN
    :	'(';

RPAREN
    :	')';

PLUS
    :	'+';

MINUS
    :	'-';

STAR
    :	'*';

SLASH
    :	'/';

EQUAL
    :   '=';

GT
    :   '>';

LT
    :   '<';

LTEQ
    :   '<=';

GTEQ
    :   '>=';

NAME
    :    ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'0'..'9'|'-'|'_')*;

NUMBER
    :   [0-9]+ ('.' [0-9]+)?;

COMMENT
    : ';' .*? '\r'? '\n' -> skip ;

WS
    :  [ \r\t\u000C\n]+ -> skip;
