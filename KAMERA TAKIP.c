using UnityEngine;
using System.Collections;

public class kameratakip : MonoBehaviour {

    Transform target;

    float xmin = 0f;
    float xmax = 7.35f;
    float ymin = 6f;
    float ymax;


	void Start () //karakterin transformuna ulasiyorum ve target adli transform degiskenine atiyorum
    {
        target = GameObject.Find("karakter").transform;

    }
	

	void LateUpdate () //burada da kameranin pozisyonuna targetin pozisyonlarini aktariyorum
    {
        if (target.position.x > xmin && target.position.x < xmax)
        {
            transform.position = new Vector3(target.position.x, target.position.y+ymin, transform.position.z);
        }
        else
        {
            transform.position = new Vector3(transform.position.x, target.position.y+ymin, transform.position.z);
        }  
    }
}
/* eger karakter pozisyon x buyukse xmin degiskeninden ve target pozisyon x kucukse xmax degerinden
transform pozisyona yeni vector 3 x pozisyonuna targetin xpozisyonunu , y pozisyonuna targetin y
pozisyonunu, z pozisyonuna kameranin z pozisyonunu aktariyorum, eger z ye target z sini verirsem
kamera goruntu alma pozisyonundan cikar ve ekranda karakter gozukmez
transform.position scripti ekledigimiz objeyi temsil eder*/
/*else 
eger bu degerler disina cikarsa ve kamera takibi birakirsa sadece target pozisyon y degerini
kameraya aktariyorum ve kamera yukari asagi yaparken hareketsiz kalmýyor
*/

////////////////////////////////////////////////////////////////////////////////////////

using UnityEngine;
using System.Collections;

public class kameratakip : MonoBehaviour {


    public Transform target;
    public float xmin;
    public float xmax;
    public float ymin;
    public float ymax;

	void Start () {
        target = GameObject.Find("karakter").transform;
	}
	
	
	void Update () {

        transform.position = new Vector3(Mathf.Clamp(target.position.x, xmin, xmax), Mathf.Clamp(target.position.y, ymin, ymax),transform.position.z);
	}
}

/NOT: MATF.CLAMP x pozisyonunun en fazla ne kadar + x deger karakter gitsin ile -x eksi deger
geri gitsin diye 2 parametreyi birbirine bagliyor.



daha basit bicimde soylede olabilir

transform.position = new vector3(target.position.x,target.position.y,transform.position.z);

boyle yaptigimizda min ve max deger vermemis oluyoruz kamera sadece karakteri takip eder sýnýr olmaz

vector3 u kameranýn z pozisyonu oldugu icin yaziyoruz
