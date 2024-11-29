import java.util.*;

public class ToggleChallenge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] digitMatrices = new String[3];
        for (int i = 0; i < 3; i++) {
            digitMatrices[i] = sc.nextLine();
        }

        String[] faultyMatrices = new String[3];
        for (int i = 0; i < 3; i++) {
            faultyMatrices[i] = sc.nextLine();
        }

        List<String[]> digits = parseDigitMatrices(digitMatrices);

        List<String[]> faultyDigits = parseDigitMatrices(faultyMatrices);

        for (String[] faultyDigit : faultyDigits) {
            if (getPossibleDigits(faultyDigit, digits).isEmpty()) {
                System.out.println("Invalid");
                return;
            }
        }

        
        long result = calculateSum(digits, faultyDigits);
        System.out.println(result);
    }

    private static List<String[]> parseDigitMatrices(String[] matrixLines) {
        List<String[]> matrices = new ArrayList<>();
        for (int i = 0; i < matrixLines[0].length(); i += 3) {
            String[] digit = new String[3];
            for (int j = 0; j < 3; j++) {
                digit[j] = matrixLines[j].substring(i, i + 3);
            }
            matrices.add(digit);
        }
        return matrices;
    }

    private static List<Integer> getPossibleDigits(String[] matrix, List<String[]> digits) {
        List<Integer> possibilities = new ArrayList<>();

        for (int i = 0; i < digits.size(); i++) {
            if (matches(matrix, digits.get(i))) {
                possibilities.add(i);
            }
        }

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                String[] toggled = toggleBit(matrix, x, y);
                for (int i = 0; i < digits.size(); i++) {
                    if (matches(toggled, digits.get(i)) && !possibilities.contains(i)) {
                        possibilities.add(i);
                    }
                }
            }
        }

        return possibilities;
    }

    private static String[] toggleBit(String[] matrix, int x, int y) {
        String[] toggled = matrix.clone();
        char[] row = toggled[x].toCharArray();
        row[y] = (row[y] == '0') ? '1' : '0';
        toggled[x] = new String(row);
        return toggled;
    }

    private static boolean matches(String[] matrix1, String[] matrix2) {
        for (int i = 0; i < 3; i++) {
            if (!matrix1[i].equals(matrix2[i])) {
                return false;
            }
        }
        return true;
    }

    private static long calculateSum(List<String[]> digits, List<String[]> faultyDigits) {
        List<Long> possibleNumbers = new ArrayList<>();

        generateNumbers(0, faultyDigits, digits, "", possibleNumbers);

        long sum = 0;
        for (long number : possibleNumbers) {
            sum += number;
        }

        return sum;
    }

    private static void generateNumbers(int index, List<String[]> faultyDigits, List<String[]> digits,
                                        String currentNumber, List<Long> possibleNumbers) {
        if (index == faultyDigits.size()) {
            possibleNumbers.add(Long.parseLong(currentNumber));
            return;
        }

        for (int digit : getPossibleDigits(faultyDigits.get(index), digits)) {
            generateNumbers(index + 1, faultyDigits, digits, currentNumber + digit, possibleNumbers);
        }
    }
}