
// Generated from ratio.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "ratioVisitor.h"


namespace lucy {

	/**
	 * This class provides an empty implementation of ratioVisitor, which can be
	 * extended to create a visitor which only needs to handle a subset of the available methods.
	 */
	class  ratioBaseVisitor : public ratioVisitor {
	public:

		virtual antlrcpp::Any visitCompilation_unit(ratioParser::Compilation_unitContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitType_declaration(ratioParser::Type_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitTypedef_declaration(ratioParser::Typedef_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitEnum_declaration(ratioParser::Enum_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitEnum_constants(ratioParser::Enum_constantsContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitClass_declaration(ratioParser::Class_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitMember(ratioParser::MemberContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitField_declaration(ratioParser::Field_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitVariable_dec(ratioParser::Variable_decContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitVoid_method_declaration(ratioParser::Void_method_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitType_method_declaration(ratioParser::Type_method_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitConstructor_declaration(ratioParser::Constructor_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitInitializer_element(ratioParser::Initializer_elementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitPredicate_declaration(ratioParser::Predicate_declarationContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitStatement(ratioParser::StatementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitBlock(ratioParser::BlockContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitAssignment_statement(ratioParser::Assignment_statementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitLocal_variable_statement(ratioParser::Local_variable_statementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitExpression_statement(ratioParser::Expression_statementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitDisjunction_statement(ratioParser::Disjunction_statementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitConjunction(ratioParser::ConjunctionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitFormula_statement(ratioParser::Formula_statementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitReturn_statement(ratioParser::Return_statementContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitAssignment_list(ratioParser::Assignment_listContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitAssignment(ratioParser::AssignmentContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitCast_expression(ratioParser::Cast_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitQualified_id_expression(ratioParser::Qualified_id_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitDivision_expression(ratioParser::Division_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitSubtraction_expression(ratioParser::Subtraction_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitExtc_one_expression(ratioParser::Extc_one_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitPlus_expression(ratioParser::Plus_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitFunction_expression(ratioParser::Function_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitAddition_expression(ratioParser::Addition_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitParentheses_expression(ratioParser::Parentheses_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitMinus_expression(ratioParser::Minus_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitImplication_expression(ratioParser::Implication_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitLt_expression(ratioParser::Lt_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitNot_expression(ratioParser::Not_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitConjunction_expression(ratioParser::Conjunction_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitGeq_expression(ratioParser::Geq_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitRange_expression(ratioParser::Range_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitMultiplication_expression(ratioParser::Multiplication_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitLeq_expression(ratioParser::Leq_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitGt_expression(ratioParser::Gt_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitConstructor_expression(ratioParser::Constructor_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitDisjunction_expression(ratioParser::Disjunction_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitLiteral_expression(ratioParser::Literal_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitEq_expression(ratioParser::Eq_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitNeq_expression(ratioParser::Neq_expressionContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitExpr_list(ratioParser::Expr_listContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitLiteral(ratioParser::LiteralContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitQualified_id(ratioParser::Qualified_idContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitType(ratioParser::TypeContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitClass_type(ratioParser::Class_typeContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitPrimitive_type(ratioParser::Primitive_typeContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitType_list(ratioParser::Type_listContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitTyped_list(ratioParser::Typed_listContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitQualified_predicate(ratioParser::Qualified_predicateContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual antlrcpp::Any visitPredicate_list(ratioParser::Predicate_listContext *ctx) override {
			return visitChildren(ctx);
		}


	};

}  // namespace lucy
