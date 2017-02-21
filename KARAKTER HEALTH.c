using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class karakterhealth : MonoBehaviour
{


    public Slider healtslider; // CANVAS UI healt bar icin
    public Image hurtscreen; //CANVAS damage yedigimizde blood ekrani icin
    float maxkarakterhealth = 100f;
    float enemydamage = 10f;
    float pushback = 10f;
    float saglik = 10f;
    GameObject hearth; // can alinca yok etmek icin




    void Start()
    {
        healtslider.maxValue = maxkarakterhealth;
        healtslider.value = maxkarakterhealth;
        hearth = GameObject.Find("heart");
    }


    void Update()
    {
        if (maxkarakterhealth <= 0)
        {
            Destroy(gameObject);
        }

    }

    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "enemy")
        {
            maxkarakterhealth = maxkarakterhealth - enemydamage;
            healtslider.value = maxkarakterhealth;
            hurtscreen.color = new Color(1f, 0f, 0f, 0.5f);
            GetComponent<Rigidbody2D>().velocity = (new Vector2(0, pushback));
        }
        else
        {
            hurtscreen.color = new Color(0f, 0f, 0f, 0f);
        }
        if (col.gameObject.tag == "saglik")
        {
            healtslider.value = healtslider.value + saglik;
        }
    }
}
