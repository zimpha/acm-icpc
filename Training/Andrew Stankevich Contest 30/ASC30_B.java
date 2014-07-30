/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author zimpha
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        Scanner cin = new Scanner(new File("derangements.in"));
        PrintWriter cout = new PrintWriter(new File("derangements.out"));
        int n = cin.nextInt();
        BigInteger comb[][] = new BigInteger[300][300];
        for (int i = 0; i <= n; ++ i) {
            comb[i][0] = comb[i][i] = BigInteger.ONE;
            for (int j = 1; j < i; ++ j) {
                comb[i][j] = comb[i - 1][j].add(comb[i - 1][j - 1]);
            }
        }
        BigInteger D[] = new BigInteger[300];
        D[0] = BigInteger.ZERO;
        D[1] = BigInteger.ZERO;
        D[2] = BigInteger.ONE;
        for (int i = 3; i <= n; ++ i) {
            D[i] = BigInteger.valueOf(i - 1).multiply(D[i - 1].add(D[i - 2]));
        }
        BigInteger P[] = new BigInteger[300];
        P[0] = BigInteger.ONE;
        for (int i = 1; i <= n; ++ i) {
            P[i] = P[i - 1].shiftLeft(1);
        }
        BigInteger ret = BigInteger.ONE;
        for (int i = 0; i <= n; ++ i) {
            ret = ret.add(comb[n][i].multiply(D[n - i]).multiply(P[n - i]));
        }
        cout.println(ret);
        cin.close();
        cout.close();
    }
    
}
