using UnityEngine;
using System.Collections;

public class healtpickup : MonoBehaviour {

	//saglik veren obje player tarafindan alindiginda objeyi siliyor
	
	void Start () {
	
	}
	
	
	void Update () {
	
	}

    void OnTriggerEnter2D(Collider2D col)
    {
        if(col.gameObject.tag == "Player")
        {
            Destroy(gameObject);
        }       
    }
}
