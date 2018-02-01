# [저항](https://www.acmicpc.net/problem/1076)

## 문제
전자 제품에는 저항이 들어간다. 저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다.

처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다.

저항의 값은 다음 표를 이용해서 구한다.

<table class="table table-bordered" style="width:30%">
<thead>
<tr>
<th style="width:10%">색</th>
<th style="width:10%">값</th>
<th style="width:10%">곱</th>
</tr>
</thead>
<tbody>
<tr>
<td>black</td>
<td>0</td>
<td>1</td>
</tr>
<tr>
<td>brown</td>
<td>1</td>
<td>10</td>
</tr>
<tr>
<td>red</td>
<td>2</td>
<td>100</td>
</tr>
<tr>
<td>orange</td>
<td>3</td>
<td>1000</td>
</tr>
<tr>
<td>yellow</td>
<td>4</td>
<td>10000</td>
</tr>
<tr>
<td>green</td>
<td>5</td>
<td>100000</td>
</tr>
<tr>
<td>blue</td>
<td>6</td>
<td>1000000</td>
</tr>
<tr>
<td>violet</td>
<td>7</td>
<td>10000000</td>
</tr>
<tr>
<td>grey</td>
<td>8</td>
<td>100000000</td>
</tr>
<tr>
<td>white</td>
<td>9</td>
<td>1000000000</td>
</tr>
</tbody>
</table>

예를 들어, 저항에 색이 yellow, violet, red였다면 저항의 값은 4,700이 된다.

## 입력
첫째 줄에 첫번째 색, 둘째 줄에 두번째 색, 셋째 줄에 세번째 색이 주어진다. 색은 모두 위의 표에 써 있는 색만 주어진다.

## 출력
첫째 줄에 입력을 주어진 저항의 저항값을 출력한다.

## 분류
- 수학
