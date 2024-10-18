#include <stdio.h>
#include <math.h>

//  payments for a loan
double calculateMonthlyPayment(double principal, double annualInterestRate, int loanTermMonths) {
    double monthlyInterestRate = annualInterestRate / 12 / 100;
    return (principal * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -loanTermMonths));
}

// display loan options
void displayLoanOptions() {
    printf("Available Loan Options:\n");
    printf("1. Personal Loan (Interest Rate: 5.5%%, Term: 5 years)\n");
    printf("2. Home Loan (Interest Rate: 3.75%%, Term: 15 years)\n");
    printf("3. Car Loan (Interest Rate: 4.25%%, Term: 7 years)\n");
}

// show repayment schedule
void showRepaymentSchedule(double principal, double annualInterestRate, int loanTermMonths) {
    double monthlyPayment = calculateMonthlyPayment(principal, annualInterestRate, loanTermMonths);
    double remainingBalance = principal;
    double monthlyInterestRate = annualInterestRate / 12 / 100;

    printf("\nRepayment Schedule:\n");
    printf("Month\tPayment\t\tInterest\tPrincipal\tRemaining Balance\n");
    for (int i = 1; i <= loanTermMonths; i++) {
        double interestPayment = remainingBalance * monthlyInterestRate;
        double principalPayment = monthlyPayment - interestPayment;
        remainingBalance -= principalPayment;
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, monthlyPayment, interestPayment, principalPayment, remainingBalance);
    }
}

// Main function for loan application process
int main() {
    int loanOption;
    double principal;
    double annualInterestRate;
    int loanTermMonths;

    displayLoanOptions();

    printf("Select a loan option (1-3): ");
    scanf("%d", &loanOption);

    switch (loanOption) {
        case 1:
            annualInterestRate = 5.5;
            loanTermMonths = 5 * 12;
            break;
        case 2:
            annualInterestRate = 3.75;
            loanTermMonths = 15 * 12;
            break;
        case 3:
            annualInterestRate = 4.25;
            loanTermMonths = 7 * 12;
            break;
        default:
            printf("Invalid loan option selected.\n");
            return 1;
    }

    printf("Enter the loan amount (principal): ");
    scanf("%lf", &principal);

    double monthlyPayment = calculateMonthlyPayment(principal, annualInterestRate, loanTermMonths);
    double totalPayment = monthlyPayment * loanTermMonths;

    printf("\nLoan Summary:\n");
    printf("Principal: $%.2f\n", principal);
    printf("Annual Interest Rate: %.2f%%\n", annualInterestRate);
    printf("Loan Term: %d years (%d months)\n", loanTermMonths / 12, loanTermMonths);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);

    showRepaymentSchedule(principal, annualInterestRate, loanTermMonths);

    return 0;
}
