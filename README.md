<h1>Förklaring av branches:</h1>
<ul>
    <li>
    <strong>MAIN =</strong> Ska bara ta emot merges från DEV och måste vara senast fungerande kod.
    </li>
    </p>
    <li>
    <strong>DEV =</strong> Komplett kod för bilen merga ingenting som inte fungerar till MAIN, inte små delkod för komponenter som servo eller motodrivaren.
    </li>
    </p>
    <li>
    <strong>KOD_BIBLIOTEK =</strong> Samlingar av olika relevanta grejer till projekten, såsom kopplinschema, dokumentation, eller delkod för att få specifika komponenter att fungerar.
    </li>
</ul>
<h1>Deployment process</h1>
<strong>
Innan merg till MAIN, var minst 2st och gå igenom koden tillsammans.
</strong>
</p>

<strong>Om ändringar görs till hela bilen</strong>
Gör en ny branch från MAIN och skriv dina ändringar...när det är färdig merga det till DEV och sen om bilan kan köra merga det till MAIN.
</p>
<strong>Om ändringar görs till en komponent</strong>
Gör en ny branch från KOD_BIBLIOTEK och skriv dina ändringar...när det är färdig merga det till KOD_BIBLIOTEK.
</p>
<strong>För att "Göra en ny branch från en befintlig branch : </strong>
</p>
Öppna Github Desktop -> Kod_Bibliotek -> Branch -> New Branch -> Create branch based on...
</p>
<strong>För att merga från en branch till en annan</strong>
</p>
Välj din branch i Github Desktop som är din destionation, Inuti Github Desktop -> Branch -> Merge into current branch -> välj den branchen som du vill merga intill din nuvarande branch.

<p>
<h1>Merge confilict</h1>
Om merge conflict uppstår, starta en diskussion och kom överens om vems kod som ska in först.
