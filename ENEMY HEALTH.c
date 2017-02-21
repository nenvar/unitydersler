using UnityEngine;
using System.Collections;

public class enemyhealt : MonoBehaviour
{

    // Use this for initialization

    float enemycan = 20f;
    float weapondamage = 10f;
    public GameObject heart; // saglik veren obje icin

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (enemycan <= 0f)
        {
            Destroy(gameObject);
            Instantiate(heart, transform.position, transform.rotation);
        }
    }


    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "roket")
        {
            enemycan = enemycan - weapondamage;
        }
    }
}
