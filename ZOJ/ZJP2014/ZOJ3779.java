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

    public static BigInteger comb(long N, long M) {
        BigInteger ret = BigInteger.ONE;
        for (int i = 0; i < M; ++ i) ret = ret.multiply(BigInteger.valueOf(N - i));
        for (int i = 0; i < M; ++ i) ret = ret.divide(BigInteger.valueOf(i + 1));
        return ret;
    }
    
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger cnt[] = new BigInteger[20];
        cnt[4] = BigInteger.valueOf(576);
        cnt[5] = BigInteger.valueOf(587520);
        cnt[6] = BigInteger.valueOf(133583040);
        cnt[7] = BigInteger.valueOf(7912114560L);
        cnt[8] = BigInteger.valueOf(183561517440L);
        cnt[9] = BigInteger.valueOf(2100291379200L);
        cnt[10] = BigInteger.valueOf(13489759180800L);
        cnt[11] = BigInteger.valueOf(52314638745600L);
        cnt[12] = BigInteger.valueOf(126988114176000L);
        cnt[13] = BigInteger.valueOf(193984151961600L);
        cnt[14] = BigInteger.valueOf(180982132531200L);
        cnt[15] = BigInteger.valueOf(94152554496000L);
        cnt[16] = BigInteger.valueOf(20922789888000L);
        int T = cin.nextInt();
        while (T > 0) {
            long N = cin.nextLong();
            BigInteger ret = BigInteger.ZERO;
            for (int i = 4; i <= N && i <= 16; ++ i) {
                ret = ret.add(cnt[i].multiply(comb(N, i)));
            }
            ret = ret.pow(4);
            System.out.println(ret);
            T --;
        }
    }
}

